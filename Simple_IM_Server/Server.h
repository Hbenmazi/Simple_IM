#pragma once
#include <qobject.h>
#include<qmutex.h>
#include<qtcpserver.h>


/**
 * @brief 作为服务器的facade类
 * 描述：使用单例模式，服务器端中其它类通过Server类与客户端通信，同时服务器
 *       接收的消息首先由Server接收，然后分发给其它类进行处理
 */
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

	QTcpServer*             chatServer;//用于监听tcp连接的建立
	QVector<QTcpSocket*>*   allClients;//目前已经建立连接的套接字

	Server();
	~Server();

private slots:
	void newClientConnection();
	void socketDisconnected();
	void socketReadyRead();
	void socketStateChanged(QAbstractSocket::SocketState stste);


};

