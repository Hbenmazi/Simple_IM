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

bool Client::SendMessageToServer(QJsonDocument& msg)
{
	QTcpSocket* socket = getSocket();
	socket->connectToHost("127.0.0.1", 8001);
	QByteArray data = msg.toJson();

	if (socket->write(data) == -1)
	{
		qDebug() << "fail to send msg";
		qDebug() << socket->errorString();
		return false;
	}
	else
	{
		qDebug() << "success to send msg";
		return true;
	}


}