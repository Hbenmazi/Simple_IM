#pragma once
#include"qstring.h"
#include"qtcpsocket.h"

/**
 * @brief 服务器端以登录的用户
 */
class User
{
public:
	User();
	User(int user_id,QString username,QTcpSocket* socket);
	~User();

	void setUserId(int user_id);
	void setUsername(QString username);
	void setSocket(QTcpSocket* socket);
	void setFileSocket(QTcpSocket* fileSocket);
	int getUserId() const;
	QString getUsername() const;
	QTcpSocket* getSocket() const;
	QTcpSocket* getFileSocket() const;

private:
	int user_id;					//用户ID
	QString username = "";			//用户名
	QTcpSocket* socket;				//与客户端连接的套接字
	QTcpSocket* fileSocket = NULL;	//用于文件传输的套接字
};

