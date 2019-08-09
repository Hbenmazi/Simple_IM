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
	QByteArray data = QByteArray(client->readAll());
	qDebug() << "\nMessage: " + data + " (" + socketIpAddress + ":" + QString::number(port) + ")\n";

	
	

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
