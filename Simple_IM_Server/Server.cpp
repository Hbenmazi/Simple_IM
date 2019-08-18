#include "Server.h"
#include "qtcpsocket.h"
#include "qjsonobject.h"
#include "Global.h"
#include "Register.h"
#include "Login.h"
#include "../Simple_IM/MsgType.h"
#include "Add.h"
#include "List.h"
 QMutex Server::mutex;
 Server*  Server::m_instance = NULL;

 Server* Server::getInstance()
 {
	 if (!m_instance)
	 {
		 QMutexLocker locker(&mutex);
		 if (!m_instance)
		 {
			 m_instance = new Server();
		 }

	 }
	 return m_instance;
}

 /**
 *Function: SendMessageToClient
 *Description: ������Ϣ���ͻ���
 *param:
 *	-msg:��Ϣ����
 *	-socket:���ӿͻ��˵��׽���
 *return:���ͳɹ�������
 */
 bool Server::SendMessageToClient(QJsonDocument & msg, QTcpSocket* socket)
 {
	 //����׽��ֵ�״̬�Ƿ�Ϊ������
	 if (socket->state() == QAbstractSocket::SocketState::ConnectedState)
	 {
		 //�����ݴ�msg��ȡ��
		 QByteArray data = msg.toJson();

		 //������д���׽���
		 if (socket->write(data) == -1)
		 {
			 //�������ʧ�ܷ��ش�����Ϣ
			 qDebug() << "Server:";
			 qDebug() << "fail to send msg";
			 qDebug() << socket->errorString();
			 return false;
		 }
		 else
		 {
			 qDebug() << "Server:";
			 qDebug() << "success to send msg";
			 return true;
		 }
	 }
	 else
	 {
		 qDebug() << "Server error:";
		 qDebug() << "socket'state:" << socket->state();
	 }
	 return false;
 }

 /**
 *Function: StartServer
 *Description: ��ʼ���������������ԣ���ʼ����
 */
 void Server::StartServer()
 {
	
	 //��ʼ������
	 allClients = new QVector<User*>;
	 chatServer = new QTcpServer();
	 fileServer = new QTcpServer();
	 
	 reg = Register::getInstance();
	 login = Login::getInstance();
	 add = Add::getInstance();
	 list = List::getInstance();
	 log = Log::getInstance();

	 //���������������Ϊ10
	 chatServer->setMaxPendingConnections(10);

	 //������µ����ӽ����򽻸�newClientConnection��������
	 connect(chatServer, SIGNAL(newConnection()), this, SLOT(newClientConnection()));
	 connect(fileServer, SIGNAL(newConnection()), this, SLOT(newClientConnection()));
	 
	 //��ʼ����
	 if (chatServer->listen(QHostAddress::Any, 8001))
	 {
		 qDebug() << "\nServer has started. Listening to port 8001.\n";
	 }
	 else
	 {
		 qDebug() << "\nServer failed to start. Error: " + chatServer->errorString()+"\n";
	 }

	 if (fileServer->listen(QHostAddress::Any, 8002))
	 {
		 qDebug() << "\nFile Server has started. Listening to port 8002.\n";
	 }
	 else
	 {
		 qDebug() << "\nFile Server failed to start. Error: " + chatServer->errorString() + "\n";
	 }

 }

 /**
 *Function: RegisterClient
 *Description: ���µ�¼���û������allClients�б�
 *param:
 *	-user_id:�û�ID
 *	-username:�û���
 *	-client:���ӿͻ��˵��׽���
 */
 void Server::RegisterClient(int user_id,QString username, QTcpSocket * client)
 {
	 User* user = new User(user_id, username, client);
	 allClients->push_back(user);

	 emit newClientSignIn(user_id, username, client);
 }

 /**
 *Function: SearchUserBySocket
 *Description: ͨ����ͻ������ӵ��׽�����allClinets�б��в����û�
 *param:
 *	-socket:��ͻ������ӵ��׽���
 *return:ָ����û���ָ��
 */
 User * Server::SearchUserBySocket(QTcpSocket * socket)
 {
	 for (int i = 0; i < allClients->size(); ++i) {
		 if (allClients->at(i)->getSocket() == socket)
			 return allClients->at(i);
	 }

	 return NULL;
 }

 QVector<User*>* Server::getAllClients()
 {
	 return allClients;
 }

 /**
 *Function: newClientConnection
 *Description: ����server����������tcp����
 */
 void Server::newClientConnection()
 {
	 //��ȡ������
	 QTcpServer* server = qobject_cast<QTcpServer*>(QObject::sender());

	 if (server == chatServer)//�������������
	 {
		 //��ȡ�׽���
		 QTcpSocket* client = chatServer->nextPendingConnection();

		 //��ȡ�ͻ��˵�IP��ַ�Ͷ˿ں�
		 QString ipAddress = client->peerAddress().toString();
		 int port = client->peerPort();
		 qDebug() << "\nSocket connected from " + ipAddress + ":" + QString::number(port) << "\n";

		 //���źŲ�
		 connect(client, &QTcpSocket::disconnected, this, &Server::socketDisconnected);
		 connect(client, &QTcpSocket::readyRead, this, &Server::socketReadyRead);
		 connect(client, &QTcpSocket::stateChanged, this, &Server::socketStateChanged);


	 }
	 else//�����ļ����������
	 {
		 //��ȡ�׽���
		 QTcpSocket* client = fileServer->nextPendingConnection();

		 //���źŲ�
		 connect(client, &QTcpSocket::disconnected, this, &Server::fileSocketDisconnected);
		 connect(client, &QTcpSocket::readyRead, this, &Server::fileSocketReadyRead);
		 connect(client, &QTcpSocket::stateChanged, this, &Server::fileSocketStateChanged);
	 }
 }
 

 void Server::socketDisconnected()
{


	//nothing but display info in console
	QTcpSocket* client = qobject_cast<QTcpSocket*>(QObject::sender());
	QString socketIpAddress = client->peerAddress().toString();
	int port = client->peerPort();
	qDebug() << "Socket disconnected from " + socketIpAddress + ":" + QString::number(port);

	int flag = 0;//��ʶ�Ƿ���allClients�����ҵ��Ͽ����û�
	int index = 0;//�ǳ��û���allclients�е�����
	for (index = 0; index < allClients->size(); index++)
	{
		if (allClients->value(index)->getSocket() == client)//��allClients���ҵ��˸��û�
		{
			flag = 1;
			break;
		}
	}

	if (flag == 1)//��allClients���ҵ��˸��û�
	{
		//��ȡ���ǳ����û�
		User* logoutUser = allClients->value(index);
		emit ClientLogOut(logoutUser->getUserId(), logoutUser->getUsername(), client);

		logoutUser->~User();
		//���ѵ�¼���б����Ƴ�
		allClients->removeAt(index);
	}
}

/**
*Function: socketReadyRead
*Description: ���ͷ��˴�����Ϣ��������ʱ�����øú������д���
*/
void Server::socketReadyRead()
{
	// use QObject::sender() to get the pointer of the object that emitted the readyRead signal
    // and convert it to the QTcpSocket class so that we can access its readAll() function.
	QTcpSocket* client = qobject_cast<QTcpSocket*>(QObject::sender());

	//get ip and port
	QString socketIpAddress = client->peerAddress().toString();
	int port = client->peerPort();

	//read the data
	QString data_string = QString(client->readAll());
	qDebug() << "\nMessage: " + data_string + " (" + socketIpAddress + ":" + QString::number(port) + ")\n";

	QVector<QJsonObject> dataArray = getJsonObjectArrayFromString(data_string);//����Ϣת����JSON��ʽ

	//�����е�ÿһ����Ϣ���д���
	for (QJsonObject data : dataArray)
	{
		//�ж���Ϣ����
		switch (data.value("type").toInt())
		{
		case MsgType::signup:
			reg->SignUp(data, client);
			break;

		case MsgType::signin:
			login->SignIn(data, client);
			break;

		case MsgType::addContact:
			add->AddContact(data, client);
			break;

		case MsgType::getFriendList:
			list->ReturnList(client);
			break;

		case MsgType::getLog:
			log->ReturnLog(data, client);
			break;

		case MsgType::sendMsg:
			log->SendNewMsg(data, client);
			break;

		default:
			break;
		}
	}

	
	

}

void Server::socketStateChanged(QAbstractSocket::SocketState state)
{
	QTcpSocket* client = qobject_cast<QTcpSocket*>(QObject::sender());

	//get ip and port
	QString socketIpAddress = client->peerAddress().toString();
	int port = client->peerPort();
	QString desc;

	// nothing but display info in console according to new state
	if (state == QAbstractSocket::UnconnectedState)
		desc = "The socket is not connected.";
	else if (state == QAbstractSocket::HostLookupState)
		desc = "The socket is performing a host name lookup.";
	else if (state == QAbstractSocket::ConnectingState)
		desc = "The socket has started establishing a connection.";
	else if (state == QAbstractSocket::ConnectedState)
		desc = "A connection is established.";
	else if (state == QAbstractSocket::BoundState)
		desc = "The socket is bound to an address and port.";
	else if (state == QAbstractSocket::ClosingState)
		desc = "The socket is about to close (data may still be waiting to be written).";
	else if (state == QAbstractSocket::ListeningState)
		desc = "For internal use only.";
	qDebug() << "\nSocket state changed (" + socketIpAddress + ":" + QString::number(port) + "): " + desc+"\n";
}

void Server::fileSocketDisconnected()
{
	//nothing but display info in console
	QTcpSocket* client = qobject_cast<QTcpSocket*>(QObject::sender());
	QString socketIpAddress = client->peerAddress().toString();
	int port = client->peerPort();
	qDebug() << "File Socket disconnected from " + socketIpAddress + ":" + QString::number(port);
}

void Server::fileSocketReadyRead()
{
	QTcpSocket* client = qobject_cast<QTcpSocket*>(QObject::sender());

	//get ip and port
	QString socketIpAddress = client->peerAddress().toString();
	int port = client->peerPort();

	//read the data
	QByteArray data_byte = client->readAll();

	QJsonObject data = QJsonDocument::fromJson(data_byte).object();

	//�����е�ÿһ����Ϣ���д���
	
	//�ж���Ϣ����
	switch (data.value("type").toInt())
	{
	case MsgType::preFileTran:
		//���Ե�¼�û����ҵ����û��������������ļ������׽���
		for (User* user : *getAllClients())
		{
			if (user->getUsername() == data.value("username").toString())
			{
				user->setFileSocket(client);
			}
		}
		break;

	default:
		//�ļ���������

		//�����Ƿ����ļ�ͷ���ȵ����ļ�ͷ��Ϣ����
		QDataStream in(data_byte);
		qint64 totalSize;  
		qint64 byteReceived;  
		QString fileName;
		QString ifHeader;
		
		in >> totalSize >> byteReceived >> ifHeader;

		if (ifHeader == "header")//����Ϣ���ļ�ͷ
			in>> peerUsername >> fileName;//���öԵ��û���

		//���ļ�ת�����Եȷ�
		for (User* user : *allClients)
		{
			if (user->getUsername() == peerUsername)
				user->getFileSocket()->write(data_byte);
		}
		break;
	}
	
	
}

void Server::fileSocketStateChanged(QAbstractSocket::SocketState state)
{
	QTcpSocket* client = qobject_cast<QTcpSocket*>(QObject::sender());

	//get ip and port
	QString socketIpAddress = client->peerAddress().toString();
	int port = client->peerPort();
	QString desc;

	// nothing but display info in console according to new state
	if (state == QAbstractSocket::UnconnectedState)
		desc = "The socket is not connected.";
	else if (state == QAbstractSocket::HostLookupState)
		desc = "The socket is performing a host name lookup.";
	else if (state == QAbstractSocket::ConnectingState)
		desc = "The socket has started establishing a connection.";
	else if (state == QAbstractSocket::ConnectedState)
		desc = "A connection is established.";
	else if (state == QAbstractSocket::BoundState)
		desc = "The socket is bound to an address and port.";
	else if (state == QAbstractSocket::ClosingState)
		desc = "The socket is about to close (data may still be waiting to be written).";
	else if (state == QAbstractSocket::ListeningState)
		desc = "For internal use only.";
	qDebug() << "\nSocket state changed (" + socketIpAddress + ":" + QString::number(port) + "): " + desc + "\n";
}

Server::Server()
{
	connect(Login::getInstance(), SIGNAL(newClientSignIn(int, QTcpSocket*)), this, SLOT(onNewClientSignIn(int, QTcpSocket*)));
}


Server::~Server()
{
	for (int i = 0;i<allClients->size();i++)
	{
		allClients->value(i)->~User();
	}
}