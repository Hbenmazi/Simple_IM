#include "Client.h"
#include "qjsondocument.h"


Client* Client::m_instance = NULL;
QMutex Client::mutex;

void Client::socketConnected()
{
	qDebug() << "Connected to server.";
}

void Client::socketDisconnected()
{
	qDebug() << "Disconnected from server.";
}

void Client::socketReadyRead()
{
	qDebug() << "socketReadyRead:" << socket->readAll();
}


Client * Client::getInstance()
{
	if (!m_instance)
	{
		QMutexLocker locker(&mutex);
		if (!m_instance)
		{
			m_instance = new Client();
		}

	}
	return m_instance;
}

QTcpSocket * Client::getSocket() const
{
	return socket;
}

/**
*Function: SendMeaaageToServer
*Description: 向服务器传送message
*param:
*msg - 被传送的消息(以JSON格式传送)
*return: 发送成功则返回真
*/
bool Client::SendMessageToServer(QJsonDocument& msg)
{
	QTcpSocket* socket = getSocket();
	socket->connectToHost("127.0.0.1", 8001);

	//将数据从msg中取出
	QByteArray data = msg.toJson();

	//将数据写入套接字
	if (socket->write(data) == -1)
	{
		//如果发送失败返回错误信息
		qDebug() << "Client:";
		qDebug() << "fail to send msg";
		qDebug() << socket->errorString();
		return false;
	}
	else
	{
		qDebug() << "Client:";
		qDebug() << "success to send msg";
		return true;
	}


}

/**
*Function:       Client
*Description:    构造函数，初始化套接字并与服务器进行连接
*/
Client::Client()
{
	if (!socket)
	{
		socket = new QTcpSocket();
		connect(socket, SIGNAL(connected()), this, SLOT(socketConnected()));
		connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
		connect(socket, SIGNAL(readyRead()), this, SLOT(socketReadyRead()));

		socket->connectToHost("127.0.0.1", 8001);
	}
}
/**
*Function:       ~Client
*Description:    析构函数，断开连接
*/
Client::~Client()
{
	if (!socket)
	{
		socket->disconnectFromHost();
	}
}