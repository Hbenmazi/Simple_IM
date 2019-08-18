#include "Add.h"
#include "MsgType.h"
#include "Client.h"
#include "qjsonobject.h"
#include "qjsondocument.h"
#include "List.h"
Add::Add()
{
	connect(Client::getInstance(), SIGNAL(AddContactSuccess(QJsonObject)), this, SIGNAL(AddContactSuccess(QJsonObject)));
	connect(Client::getInstance(), SIGNAL(AddContactFail(QJsonObject)), this, SIGNAL(AddContactFail(QJsonObject)));
	connect(this, SIGNAL(AddContactSuccess(QJsonObject)), List::getInstance(), SLOT(RefreshList()));//收到添加好友成功信号后,通知List更新好友列表
}


Add::~Add()
{
}

/**
*Function: AddContact
*Description: 向服务器发出添加好友请求
*param:
	-username:发出请求的用户名
	-targetUsername:接收方的用户名
*return;发出请求成功成功返回真
*/
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
