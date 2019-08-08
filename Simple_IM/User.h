#pragma once
#include<QString>
class User
{
public:
	User();
	User(QString username, QString passward, QString nickname, QString email);
	~User();
	void SetUsername(QString username);
	void SetPassward(QString passward);
	void SetNickname(QString nickname);
	void SetEmail(QString email);

	QString GetUsername(QString username) const;
	QString GetPassward(QString passward) const;
	QString GetNickname(QString nickname) const;
	QString GetEmail(QString email) const;
	

private:
	QString username;
	QString passward;
	QString nickname;
	QString email;
};

