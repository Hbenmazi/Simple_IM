#include "Server.h"
#include"qtcpsocket.h"
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

 void Server::StartServer()
 {
	
	 allClients = new QVector<QTcpSocket*>;
	 chatServer = new QTcpServer();
	 chatServer->setMaxPendingConnections(10);
	 connect(chatServer, SIGNAL(newConnection()), this, SLOT(newClientConnection()));
	 
	 if (chatServer->listen(QHostAddress::Any, 8001))
	 {
		 qDebug() << "Server has started. Listening to port 8001.";
	 }
	 else
	 {
		 qDebug() << "Server failed to start. Error: " + chatServer->errorString();
	 }

 }
 void Server::newClientConnection()
 {
	 
	 QTcpSocket* client = chatServer->nextPendingConnection();

	 //获取客户端的IP地址和端口号
	 QString ipAddress = client->peerAddress().toString();
	 int port = client->peerPort();
	 
	 connect(client, &QTcpSocket::disconnected, this, &Server::socketDisconnected);
	 connect(client, &QTcpSocket::readyRead, this, &Server::socketReadyRead);
	 connect(client, &QTcpSocket::stateChanged, this, &Server::socketStateChanged);
	
	 allClients->push_back(client);
	 qDebug() << "Socket connected from " + ipAddress + ":" + QString::number(port);
 }

 Server::Server()
{

}


Server::~Server()
{
}

void Server::socketDisconnected()
{
	//nothing but display info in console
	QTcpSocket* client = qobject_cast<QTcpSocket*>(QObject::sender());
	QString socketIpAddress = client->peerAddress().toString();
	int port = client->peerPort();
	qDebug() << "Socket disconnected from " + socketIpAddress + ":" + QString::number(port);
}

void Server::socketReadyRead()
{
	// use QObject::sender() to get the pointer of the object that emitted the readyRead signal
    // and convert it to the QTcpSocket class so that we can access its readAll() function.
	QTcpSocket* client = qobject_cast<QTcpSocket*>(QObject::sender());

	//get ip and port
	QString socketIpAddress = client->peerAddress().toString();
	int port = client->peerPort();

	//read the data
	QString data = QString(client->readAll());
	qDebug() << "Message: " + data + " (" + socketIpAddress + ":" + QString::number(port) + ")";
	

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
	qDebug() << "Socket state changed (" + socketIpAddress + ":" + QString::number(port) + "): " + desc;
}
