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
*Description: 向客户端传送message
*param:
*msg - 被传送的消息(以JSON格式传送)
*socket - 与目标客户端连接的套接字
*return: 发送成功则返回真
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
*Description: 开启服务区监听客户端发起的连接
*/
 void Server::StartServer()
 {
	
	 allClients = new QVector<QTcpSocket*>;
	 chatServer = new QTcpServer();

	 //设置最大连接数量为10
	 chatServer->setMaxPendingConnections(10);

	 //如果有新的连接建立则交给newClientConnection函数处理
	 connect(chatServer, SIGNAL(newConnection()), this, SLOT(newClientConnection()));
	 
	 //开始监听
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
*Description: 新连接产生后，将套接字放入vector中
*/
 void Server::newClientConnection()
 {
	 
	 QTcpSocket* client = chatServer->nextPendingConnection();

	 //获取客户端的IP地址和端口号
	 QString ipAddress = client->peerAddress().toString();
	 int port = client->peerPort();
	 
	 connect(client, &QTcpSocket::disconnected, this, &Server::socketDisconnected);
	 connect(client, &QTcpSocket::readyRead, this, &Server::socketReadyRead);
	 connect(client, &QTcpSocket::stateChanged, this, &Server::socketStateChanged);
	
	 //将新的套接字放入vector中
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
	QJsonObject data = getJsonObjectFromString(data_string);//将消息转化成JSON格式
	
	//判断消息类型
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