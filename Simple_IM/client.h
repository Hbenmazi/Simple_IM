#pragma once
#include <qobject.h>
#include<qtcpsocket.h>
#include<qmutex.h>

class Client :
	public QObject
{
	Q_OBJECT

public:
	static Client* getInstance();
	QTcpSocket* getSocket() const;
	bool SendMessageToServer(QJsonDocument&  msg);


private:
	static Client* m_instance;
	static QMutex mutex;
	QTcpSocket* socket = NULL;

	Client()
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
	~Client()
	{
		if (!socket)
		{
			socket->disconnectFromHost();
		}
	}

private slots:
	void socketConnected();
	void socketDisconnected();
	void socketReadyRead();

	
};

