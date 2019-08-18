#include "Register.h"
#include "User.h"
#include "qjsonvalue.h"
#include "qjsonobject.h"
#include "qjsondocument.h"
#include "Client.h"
#include "MsgType.h"
Register::Register()
{
	connect(Client::getInstance(), SIGNAL(SignUpSuccess()), this, SLOT(onSignUpSuccess()));
	connect(Client::getInstance(), SIGNAL(SignUpFail(QString)), this, SLOT(onSignUpFail(QString)));
}


Register::~Register()
{
}

/**
*Function: SignUp
*Description: 向服务器发送注册请求
*param:
*	-username:     用户名
*	-passward:     密码
*	-nickname:     昵称
*	-emial:	       电子邮箱
*	-profile_index:头像图片索引
*return:登陆成功返回真
*/
bool Register::SignUp(QString username, QString password, QString nickname, QString email, QString profile_index) const
{
	//使用JSON格式传递注册请求
	QJsonObject msg_json;
	msg_json.insert("type",MsgType::signup);//type字段设置为signup，服务器通过tyoe字段来决定要做的操作
	msg_json.insert("username", username);
	msg_json.insert("password", password);
	msg_json.insert("nickname", nickname);
	msg_json.insert("email", email);
	msg_json.insert("profile_index", profile_index);

	qDebug() << "Client Sign up:";
	qDebug() << msg_json.value("username");
	qDebug() << msg_json.value("password");
	qDebug() << msg_json.value("nickname");
	qDebug() << msg_json.value("email");
	qDebug() << msg_json.value("profile_index");

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
void Register::onSignUpSuccess() 
{
	emit SignUpSuccess();
}
void Register::onSignUpFail(QString info)
{
	emit SignUpFail(info);
}
