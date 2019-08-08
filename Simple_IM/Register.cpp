#include "Register.h"
#include "User.h"
#include "qjsonvalue.h"
#include "qjsonobject.h"
#include "qjsondocument.h"
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

	QJsonDocument msg(msg_json);






	return 1;
	
}