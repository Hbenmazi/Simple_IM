#include "Register.h"
#include "User.h"
#include "qjsonvalue.h"
#include "qjsonobject.h"
#include "qjsondocument.h"
#include "Client.h"
#include "MsgType.h"
Register::Register()
{

}


Register::~Register()
{
}

/**
*Function: Register::SignUp
*Description: 新用户注册
*param:
*username - 用户名
*passward - 密码
*nickname - 网名
*email - 电子邮箱
*return: 注册成功则返回真
*/
bool Register::SignUp(QString username, QString password, QString nickname, QString email) const
{
	//使用JSON格式传递注册请求
	QJsonObject msg_json;
	msg_json.insert("type",MsgType::signup);//type字段设置为signup，服务器通过tyoe字段来决定要做的操作
	msg_json.insert("username", username);
	msg_json.insert("password", password);
	msg_json.insert("nickname", nickname);
	msg_json.insert("email", email);

	qDebug() << "Client Sign up:";
	qDebug() << msg_json.value("username");
	qDebug() << msg_json.value("password");
	qDebug() << msg_json.value("nickname");
	qDebug() << msg_json.value("email");

	//打包为QJsonDocument格式
	QJsonDocument msg(msg_json);

	//获取facade
	Client* myClient = Client::getInstance();

	//发出请求
	if (myClient->SendMessageToServer(msg))
	{
		qDebug() << "success to send signup msg";
		return true;
	}
	else
	{
		qDebug() << "fail to signup msg";
		return false;
	}

}