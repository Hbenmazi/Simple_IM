#pragma once
#include <qobject.h>
#include<qmutex.h>
#include<qtcpserver.h>
class Server :
	public QObject
{
	Q_OBJECT

public:
	static Server* getInstance();

	void StartServer();

private:
	static QMutex mutex;
	static Server* m_instance;
	QTcpServer*             chatServer;
	QVector<QTcpSocket*>*   allClients;

	Server();
	~Server();

private slots:
	void newClientConnection();
	void socketDisconnected();
	void socketReadyRead();
	void socketStateChanged(QAbstractSocket::SocketState stste);


};

