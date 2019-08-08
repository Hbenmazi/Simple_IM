#include "User.h"



User::User(QString username,QString passward,QString nickname,QString email)
{
	SetUsername(username);
	SetPassward(passward);
	SetNickname(nickname);
	SetEmail(email);
}


User::~User()
{
}

void User::SetUsername(QString username)
{
	this->username = username;
}

void User::SetPassward(QString passward)
{
	this->passward = passward;
}

void User::SetNickname(QString nickname)
{
	this->nickname = nickname;
}

void User::SetEmail(QString email)
{
	this->email = email;
}

QString User::GetUsername(QString username) const
{
	return username;
}

QString User::GetPassward(QString passward) const
{
	return passward;
}

QString User::GetNickname(QString nickname) const
{
	return nickname;
}

QString User::GetEmail(QString email) const
{
	return email;
}
