#include "Client.h"
#include "qjsondocument.h"
#include "qtcpsocket.h"
#include "../Simple_IM_Server/Global.h"
#include "MsgType.h"
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
	//read the data
	QString msg = QString(socket->readAll());
	qDebug() << "\nMessage: " + msg;
	handleMeaasge(msg);
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
*Description: �����������message
*param:
*msg - �����͵���Ϣ(��JSON��ʽ����)
*return: ���ͳɹ��򷵻���
*/
bool Client::SendMessageToServer(QJsonDocument& msg)
{
	QTcpSocket* socket = getSocket();
	socket->connectToHost("127.0.0.1", 8001);

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

/**
*Function:       Client
*Description:    ���캯������ʼ���׽��ֲ����������������
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
*Description:    �����������Ͽ�����
*/
Client::~Client()
{
	if (!socket)
	{
		socket->disconnectFromHost();
	}
}