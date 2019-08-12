#pragma once
#include <qobject.h>
#include<qmutex.h>
#include<qtcpserver.h>
#include"qstring.h"
#include"User.h"
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
	bool SendMessageToClient(QJsonDocument&  msg,QTcpSocket* socket);
	void StartServer();
	void RegisterClient(int user_id, QString username, QTcpSocket* client);
	User* SearchUserBySocket(QTcpSocket* socket);

private:
	static QMutex mutex;
	static Server* m_instance;

	QTcpServer*             chatServer;//用于监听tcp连接的建立
	QVector<User*>*          allClients;//目前已经登陆的用户

	Server();
	~Server();

private slots:
	void newClientConnection();
	void socketDisconnected();
	void socketReadyRead();
	void socketStateChanged(QAbstractSocket::SocketState stste);

signals:
	void newClientSignIn(int user_id, QString username, QTcpSocket* client);
	void ClientLogOut(int user_id, QString username, QTcpSocket* client);

};

