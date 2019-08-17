#include "Client.h"
#include "qjsondocument.h"
#include "qtcpsocket.h"
#include "../Simple_IM_Server/Global.h"
#include "MsgType.h"
#include"Address.h"
Client* Client::m_instance = NULL;
QMutex Client::mutex;

/**
*Function:       Client
*Description:    构造函数，初始化套接字并与服务器进行连接
*/
Client::Client()
{
	connect(this, SIGNAL(SignInSuccess(QString)), this, SLOT(onSignInSuccess()));
	if (!socket)
	{
		socket = new QTcpSocket();
		connect(socket, SIGNAL(connected()), this, SLOT(socketConnected()));
		connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
		connect(socket, SIGNAL(readyRead()), this, SLOT(socketReadyRead()));

		QString ip = Address::getInstance()->getServerIp();
		int port = Address::getInstance()->getChatPort();
		socket->connectToHost(ip, port);
	}

	//filesocket在登陆成功后才连接服务器
	fileSocket = new QTcpSocket();
	connect(fileSocket, SIGNAL(readyRead()), this, SLOT(fileSocketReadyRead()));
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
	//read the data
	QString msg = QString(socket->readAll());
	qDebug() << "\nMessage: " + msg;
	handleMeaasge(msg);
}

void Client::fileSocketReadyRead()
{
	QByteArray data = fileSocket->readAll();
	emit FileSocketReadyRead(data);
	
}

void Client::onSignInSuccess()
{
	QTcpSocket* fileSocket = getFileSocket();
	QString ip = Address::getInstance()->getServerIp();
	int port = Address::getInstance()->getFilePort();
	fileSocket->connectToHost(ip, port);
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

QTcpSocket * Client::getFileSocket() const
{
	return fileSocket;
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

	QString ip = Address::getInstance()->getServerIp();
	int port = Address::getInstance()->getChatPort();
	socket->connectToHost(ip, port);

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

bool Client::SendMessageToFileServer(QJsonDocument& msg)
{
	QTcpSocket* fileSocket = getFileSocket();
	QString ip = Address::getInstance()->getServerIp();
	int port = Address::getInstance()->getFilePort();
	fileSocket->connectToHost(ip, port);

	//将数据从msg中取出
	QByteArray data = msg.toJson();

	//将数据写入套接字
	if (fileSocket->write(data) == -1)
	{
		//如果发送失败返回错误信息
		qDebug() << "Client:";
		qDebug() << "fail to send msg";
		qDebug() << fileSocket->errorString();
		return false;
	}
	else
	{
		qDebug() << "Client:";
		qDebug() << "success to send msg";
		return true;
	}


}

void Client::handleMeaasge(QString msg)
{
	QVector<QJsonObject> dataArray = getJsonObjectArrayFromString(msg);//将消息转化成JSON格式

	//对其中的每一条消息进行处理
	for (QJsonObject data : dataArray)
	{
		//判断消息类型
		switch (data.value("type").toInt())
		{
		case MsgType::signupSuccess:
			emit SignUpSuccess();
			break;

		case MsgType::signupFail:
			emit SignUpFail(data.value("info").toString());
			break;

		case MsgType::signinSuccess:
			emit SignInSuccess(data.value("username").toString());
			break;

		case MsgType::signinFail:
			emit SignInFail(data.value("info").toString());
			break;

		case MsgType::addContactSuccess:
			emit AddContactSuccess(data);
			break;

		case MsgType::addContactFail:
			emit AddContactFail(data);
			break;

		case MsgType::friendListResult:
			emit ListRefreshed(dataArray);
			break;

		case MsgType::logResult:
			emit LogRefreshed(dataArray);
			return ;
			break;

		default:
			break;
		}
	}
}

