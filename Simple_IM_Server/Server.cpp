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
 *Description: 发送消息至客户端
 *param:
 *	-msg:消息内容
 *	-socket:连接客户端的套接字
 *return:发送成功返回真
 */
 bool Server::SendMessageToClient(QJsonDocument & msg, QTcpSocket* socket)
 {
	 //检查套接字的状态是否为已连接
	 if (socket->state() == QAbstractSocket::SocketState::ConnectedState)
	 {
		 //将数据从msg中取出
		 QByteArray data = msg.toJson();

		 //将数据写入套接字
		 if (socket->write(data) == -1)
		 {
			 //如果发送失败返回错误信息
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
 *Description: 初始化服务器各项属性，开始监听
 */
 void Server::StartServer()
 {
	
	 //初始化属性
	 allClients = new QVector<User*>;
	 chatServer = new QTcpServer();
	 fileServer = new QTcpServer();
	 
	 reg = Register::getInstance();
	 login = Login::getInstance();
	 add = Add::getInstance();
	 list = List::getInstance();
	 log = Log::getInstance();

	 //设置最大连接数量为10
	 chatServer->setMaxPendingConnections(10);

	 //如果有新的连接建立则交给newClientConnection函数处理
	 connect(chatServer, SIGNAL(newConnection()), this, SLOT(newClientConnection()));
	 connect(fileServer, SIGNAL(newConnection()), this, SLOT(newClientConnection()));
	 
	 //开始监听
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
 *Description: 将新登录的用户储存进allClients列表
 *param:
 *	-user_id:用户ID
 *	-username:用户名
 *	-client:连接客户端的套接字
 */
 void Server::RegisterClient(int user_id,QString username, QTcpSocket * client)
 {
	 User* user = new User(user_id, username, client);
	 allClients->push_back(user);

	 emit newClientSignIn(user_id, username, client);
 }

 /**
 *Function: SearchUserBySocket
 *Description: 通过与客户端连接的套接字在allClinets列表中查找用户
 *param:
 *	-socket:与客户端连接的套接字
 *return:指向该用户的指针
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
 *Description: 处理server监听到的新tcp连接
 */
 void Server::newClientConnection()
 {
	 //获取发送者
	 QTcpServer* server = qobject_cast<QTcpServer*>(QObject::sender());

	 if (server == chatServer)//若是聊天服务器
	 {
		 //获取套接字
		 QTcpSocket* client = chatServer->nextPendingConnection();

		 //获取客户端的IP地址和端口号
		 QString ipAddress = client->peerAddress().toString();
		 int port = client->peerPort();
		 qDebug() << "\nSocket connected from " + ipAddress + ":" + QString::number(port) << "\n";

		 //绑定信号槽
		 connect(client, &QTcpSocket::disconnected, this, &Server::socketDisconnected);
		 connect(client, &QTcpSocket::readyRead, this, &Server::socketReadyRead);
		 connect(client, &QTcpSocket::stateChanged, this, &Server::socketStateChanged);


	 }
	 else//若是文件传输服务器
	 {
		 //获取套接字
		 QTcpSocket* client = fileServer->nextPendingConnection();

		 //绑定信号槽
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

	int flag = 0;//标识是否在allClients中能找到断开的用户
	int index = 0;//登出用户在allclients中的索引
	for (index = 0; index < allClients->size(); index++)
	{
		if (allClients->value(index)->getSocket() == client)//在allClients中找到了该用户
		{
			flag = 1;
			break;
		}
	}

	if (flag == 1)//在allClients中找到了该用户
	{
		//获取待登出的用户
		User* logoutUser = allClients->value(index);
		emit ClientLogOut(logoutUser->getUserId(), logoutUser->getUsername(), client);

		logoutUser->~User();
		//从已登录的列表中移除
		allClients->removeAt(index);
	}
}

/**
*Function: socketReadyRead
*Description: 当客服端传递消息给服务器时，调用该函数进行处理
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

	QVector<QJsonObject> dataArray = getJsonObjectArrayFromString(data_string);//将消息转化成JSON格式

	//对其中的每一条消息进行处理
	for (QJsonObject data : dataArray)
	{
		//判断消息类型
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

	//对其中的每一条消息进行处理
	
	//判断消息类型
	switch (data.value("type").toInt())
	{
	case MsgType::preFileTran:
		//在以登录用户中找到该用户，并设置他的文件传输套接字
		for (User* user : *getAllClients())
		{
			if (user->getUsername() == data.value("username").toString())
			{
				user->setFileSocket(client);
			}
		}
		break;

	default:
		//文件传输请求

		//无论是否是文件头都先当做文件头信息处理
		QDataStream in(data_byte);
		qint64 totalSize;  
		qint64 byteReceived;  
		QString fileName;
		QString ifHeader;
		
		in >> totalSize >> byteReceived >> ifHeader;

		if (ifHeader == "header")//该消息是文件头
			in>> peerUsername >> fileName;//设置对等用户名

		//将文件转发给对等方
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