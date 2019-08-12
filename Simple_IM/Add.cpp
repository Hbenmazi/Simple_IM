#include "Add.h"
#include "MsgType.h"
#include "Client.h"
#include "qjsonobject.h"
#include "qjsondocument.h"

Add::Add()
{
	connect(Client::getInstance(), SIGNAL(AddContactSuccess(QJsonObject)), this, SIGNAL(AddContactSuccess(QJsonObject)));
	connect(Client::getInstance(), SIGNAL(AddContactFail(QJsonObject)), this, SIGNAL(AddContactFail(QJsonObject)));
}


Add::~Add()
{
}

bool Add::AddContact(QString username,QString targetUsername) const
{
	//使用JSON格式传递注册请求
	QJsonObject msg_json;
	msg_json.insert("type", MsgType::addContact);
	msg_json.insert("username", username);
	msg_json.insert("targetUsername", targetUsername);

	qDebug() << "Client AddContact:";
	qDebug() << msg_json.value("username");
	qDebug() << msg_json.value("targetUsername");

	//打包为QJsonDocument格式
	QJsonDocument msg(msg_json);

	//获取facade
	Client* myClient = Client::getInstance();

	//发出请求
	if (myClient->SendMessageToServer(msg))
	{
		qDebug() << "Client AddContact:";
		qDebug() << "success to send AddContact msg";
		return true;
	}
	else
	{
		qDebug() << "Client AddContact:";
		qDebug() << "fail to send AddContact msg";
		return false;
	}
}
