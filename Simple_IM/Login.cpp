#include "Login.h"
#include"qjsonobject.h"
#include"qjsondocument.h"
#include"MsgType.h"
#include "Client.h"
#include"List.h"
Login::Login()
{
	connect(Client::getInstance(), SIGNAL(SignInSuccess(QString)), this, SLOT(onSignInSuccess(QString)));
	connect(Client::getInstance(), SIGNAL(SignInFail(QString)), this, SLOT(onSignInFail(QString)));
	connect(this, SIGNAL(SignInSuccess(QString)), List::getInstance(), SLOT(RefreshList()));
}


Login::~Login()
{
}

/**
*Function: SignIn
*Description: 向服务器发出登录请求
*param:
	-username:用户名
	-password:密码
*return;发出请求成功返回真
*/
bool Login::SignIn(QString username, QString password) const
{
	//使用JSON格式传递注册请求
	QJsonObject msg_json;
	msg_json.insert("type", MsgType::signin);//type字段设置为signup，服务器通过type字段来决定要做的操作
	msg_json.insert("username", username);
	msg_json.insert("password", password);

	qDebug() << "Client Sign in:";
	qDebug() << msg_json.value("username");
	qDebug() << msg_json.value("password");

	//打包为QJsonDocument格式
	QJsonDocument msg(msg_json);

	//获取facade
	Client* myClient = Client::getInstance();

	//发出请求
	if (myClient->SendMessageToServer(msg))
	{
		qDebug() << "Client Sign in:";
		qDebug() << "success to send signin msg";
		return true;
	}
	else
	{
		qDebug() << "Client Sign in:";
		qDebug() << "fail to send signin msg";
		return false;
	}
}

/**
*Function: onSignInSuccess
*Description: 登陆成功后转发消息，并向服务器要求初始化传输文件服务器
*param:
	-username:用户名
*/
void Login::onSignInSuccess(QString username)
{
	//转发登陆成功信息
	emit SignInSuccess(username);

	//向服务器告知，初始化文件传输服务器
	QJsonObject msg_json;
	msg_json.insert("type", MsgType::preFileTran);
	msg_json.insert("username", username);

	//打包为QJsonDocument格式
	QJsonDocument msg(msg_json);

	//获取facade并发送
	Client* myClient = Client::getInstance();
	myClient->SendMessageToFileServer(msg);

}
void Login::onSignInFail(QString info)
{
	emit SignInFail(info);
}
