#include "User.h"



User::User():user_id(-1),username(""),socket(NULL)
{
}

User::User(int user_id, QString username, QTcpSocket * socket) : user_id(user_id), username(username), socket(socket)
{
}


User::~User()
{
	socket->abort();
}

void User::setUserId(int user_id)
{
	this->user_id = user_id;
}

void User::setUsername(QString username)
{
	this->username = username;
}

void User::setSocket(QTcpSocket * socket)
{
	this->socket = socket;
}

void User::setFileSocket(QTcpSocket * fileSocket)
{
	this->fileSocket = fileSocket;
}

int User::getUserId() const
{
	return user_id;
}

QString User::getUsername() const
{
	return username;
}

QTcpSocket * User::getSocket() const
{
	return socket;
}

QTcpSocket * User::getFileSocket() const
{
	return fileSocket;
}
