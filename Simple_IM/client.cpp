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