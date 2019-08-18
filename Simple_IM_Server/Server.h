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

	/**
	*Function: SendMessageToClient
	*Description: 发送消息至客户端
	*param:
	*	-msg:消息内容
	*	-socket:连接客户端的套接字
	*return:发送成功返回真
	*/
	bool SendMessageToClient(QJsonDocument&  msg,QTcpSocket* socket);

	/**
	*Function: StartServer
	*Description: 初始化服务器各项属性，开始监听
	*/
	void StartServer();

	/**
	*Function: RegisterClient
	*Description: 将新登录的用户储存进allClients列表
	*param:
	*	-user_id:用户ID
	*	-username:用户名
	*	-client:连接客户端的套接字
	*/
	void RegisterClient(int user_id, QString username, QTcpSocket* client);
	
	/**
	*Function: SearchUserBySocket
	*Description: 通过与客户端连接的套接字在allClinets列表中查找用户
	*param:
	*	-socket:与客户端连接的套接字
	*return:指向该用户的指针
	*/
	User* SearchUserBySocket(QTcpSocket* socket);

	QVector<User*>*  getAllClients();

private:
	static QMutex mutex;
	static Server* m_instance;

	QTcpServer* chatServer;     //聊天服务器
	QTcpServer* fileServer;     //文件传输服务器
	QVector<User*>* allClients; //目前已经登陆的用户
	QString peerUsername;       //文件传输时接收方的用户名

	Register* reg;	//处理注册请求
	Login* login;	//处理登录请求
	Add* add;		//处理添加好友请求
	List* list;		//处理好友列表请求
	Log* log;		//处理聊天记录请求


	Server();
	~Server();

private slots:
	/**
	*Function: newClientConnection
	*Description: 处理server监听到的新tcp连接
	*/
	void newClientConnection();

	/*聊天套接字和 传输文件套接字状态改变后会触发以下函数*/
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

