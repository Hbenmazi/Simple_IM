#include "Register.h"
#include "User.h"
#include "qjsonvalue.h"
#include "qjsonobject.h"
#include "qjsondocument.h"
#include "Client.h"
Register::Register()
{

}


Register::~Register()
{
}

bool Register::SignUp(QString username, QString password, QString nickname, QString email) const
{
	
	QJsonObject msg_json;
	msg_json.insert("type","signup");
	msg_json.insert("username", username);
	msg_json.insert("password", password);
	msg_json.insert("nickname", nickname);
	msg_json.insert("email", email);
	qDebug()<<msg_json.value("username");
	qDebug() << msg_json.value("password");
	qDebug() << msg_json.value("nickname");
	qDebug() << msg_json.value("email");

	QJsonDocument msg(msg_json);
	Client* myClient = Client::getInstance();

	if (myClient->SendMessageToServer(msg))
		return true;
	else
		return false;

}