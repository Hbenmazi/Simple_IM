#include "Server.h"
#include "qtcpsocket.h"
#include "qjsonobject.h"
#include "Global.h"
#include "Register.h"
#include "Login.h"
#include "../Simple_IM/MsgType.h"

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
*Description: ��ͻ��˴���message
*param:
*msg - �����͵���Ϣ(��JSON��ʽ����)
*socket - ��Ŀ��ͻ������ӵ��׽���
*return: ���ͳɹ��򷵻���
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
*Description: ���������������ͻ��˷��������
*/
 void Server::StartServer()
 {
	
	 allClients = new QVector<QTcpSocket*>;
	 chatServer = new QTcpServer();

	 //���������������Ϊ10
	 chatServer->setMaxPendingConnections(10);

	 //������µ����ӽ����򽻸�newClientConnection��������
	 connect(chatServer, SIGNAL(newConnection()), this, SLOT(newClientConnection()));
	 
	 //��ʼ����
	 if (chatServer->listen(QHostAddress::Any, 8001))
	 {
		 qDebug() << "\nServer has started. Listening to port 8001.\n";
	 }
	 else
	 {
		 qDebug() << "\nServer failed to start. Error: " + chatServer->errorString()+"\n";
	 }

 }

 void Server::RegisterClient(QTcpSocket * client)
 {
	 allClients->push_back(client);
 }

/**
*Function: newClientConnection
*Description: �����Ӳ����󣬽��׽��ַ���vector��
*/
 void Server::newClientConnection()
 {
	 
	 QTcpSocket* client = chatServer->nextPendingConnection();

	 //��ȡ�ͻ��˵�IP��ַ�Ͷ˿ں�
	 QString ipAddress = client->peerAddress().toString();
	 int port = client->peerPort();
	 
	 connect(client, &QTcpSocket::disconnected, this, &Server::socketDisconnected);
	 connect(client, &QTcpSocket::readyRead, this, &Server::socketReadyRead);
	 connect(client, &QTcpSocket::stateChanged, this, &Server::socketStateChanged);
	
	 //���µ��׽��ַ���vector��
	 allClients->push_back(client);

	 qDebug() << "\nSocket connected from " + ipAddress + ":" + QString::number(port)<<"\n";
 }
 

void Server::socketDisconnected()
{
	//nothing but display info in console
	QTcpSocket* client = qobject_cast<QTcpSocket*>(QObject::sender());
	QString socketIpAddress = client->peerAddress().toString();
	int port = client->peerPort();
	qDebug() << "Socket disconnected from " + socketIpAddress + ":" + QString::number(port);
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
	QJsonObject data = getJsonObjectFromString(data_string);//����Ϣת����JSON��ʽ
	
	//�ж���Ϣ����
	switch (data.value("type").toInt())
	{
		case MsgType::signup:
			Register::getInstance()->SignUp(data);
			break;

		case MsgType::signin:
			Login::getInstance()->SignIn(data, client);
			break;

		default:
			break;
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

Server::Server()
{

}


Server::~Server()
{
}