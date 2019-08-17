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
*Description:    ���캯������ʼ���׽��ֲ����������������
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

	//filesocket�ڵ�½�ɹ�������ӷ�����
	fileSocket = new QTcpSocket();
	connect(fileSocket, SIGNAL(readyRead()), this, SLOT(fileSocketReadyRead()));
}

/**
*Function:       ~Client
*Description:    �����������Ͽ�����
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
*Description: �����������message
*param:
*msg - �����͵���Ϣ(��JSON��ʽ����)
*return: ���ͳɹ��򷵻���
*/
bool Client::SendMessageToServer(QJsonDocument& msg)
{
	QTcpSocket* socket = getSocket();

	QString ip = Address::getInstance()->getServerIp();
	int port = Address::getInstance()->getChatPort();
	socket->connectToHost(ip, port);

	//�����ݴ�msg��ȡ��
	QByteArray data = msg.toJson();

	//������д���׽���
	if (socket->write(data) == -1)
	{
		//�������ʧ�ܷ��ش�����Ϣ
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

	//�����ݴ�msg��ȡ��
	QByteArray data = msg.toJson();

	//������д���׽���
	if (fileSocket->write(data) == -1)
	{
		//�������ʧ�ܷ��ش�����Ϣ
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
	QVector<QJsonObject> dataArray = getJsonObjectArrayFromString(msg);//����Ϣת����JSON��ʽ

	//�����е�ÿһ����Ϣ���д���
	for (QJsonObject data : dataArray)
	{
		//�ж���Ϣ����
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

