#pragma once
#include"qstring.h"
#include"qtcpsocket.h"
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
	int user_id;
	QString username = "";
	QTcpSocket* socket;
	QTcpSocket* fileSocket = NULL;


};

