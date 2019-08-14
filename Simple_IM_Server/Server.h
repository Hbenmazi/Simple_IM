#pragma once
#include <qobject.h>
#include<qmutex.h>
#include<qtcpserver.h>
#include"qstring.h"
#include"User.h"
#include"Register.h"
#include"Login.h"
#include"Add.h"
#include"List.h"
#include"Log.h"
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
	QVector<User*>*  getAllClients();

private:
	static QMutex mutex;
	static Server* m_instance;

	QTcpServer* chatServer;//用于监听tcp连接的建立
	QTcpServer* fileServer;//用于传输文件
	QVector<User*>* allClients;//目前已经登陆的用户
	QString peerUsername;//文件传输时接收方的用户名

	Register* reg;
	Login* login;
	Add* add;
	List* list;
	Log* log;


	Server();
	~Server();

private slots:
	void newClientConnection();
	void socketDisconnected();
	void socketReadyRead();
	void socketStateChanged(QAbstractSocket::SocketState state);
	void fileSocketDisconnected();
	void fileSocketReadyRead();
	void fileSocketStateChanged(QAbstractSocket::SocketState state);

signals:
	void newClientSignIn(int user_id, QString username, QTcpSocket* client);
	void ClientLogOut(int user_id, QString username, QTcpSocket* client);

};

