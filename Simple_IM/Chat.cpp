#include "Chat.h"
#include "Client.h"
#include "MsgType.h"
#include "qjsonobject.h"
#include "qjsondocument.h"
Chat::Chat()
{
	connect(Client::getInstance(), SIGNAL(LogRefreshed(QVector<QJsonObject>)), this, SLOT(onLogRefreshed(QVector<QJsonObject>)));
}


Chat::~Chat()
{
}


/**
*Function: RefreshLog
*Description: 向服务器提交刷新聊天窗口的请求
*param:
	-username:本机用户名
	-peerUsername:对等方用户名
*/
void Chat::RefreshLog(QString username, QString peerUsername)
{
	QJsonObject msg_json;
	msg_json.insert("type", MsgType::getLog);
	msg_json.insert("username", username);
	msg_json.insert("peerUsername", peerUsername);

	qDebug() << "Client RefreshLog:";
	qDebug() << msg_json.value("username");
	qDebug() << msg_json.value("peerUsername");

	//打包为QJsonDocument格式
	QJsonDocument msg(msg_json);

	//获取facade
	Client* myClient = Client::getInstance();

	//发出请求
	if (myClient->SendMessageToServer(msg))
	{
		qDebug() << "Client  RefreshLog:";
		qDebug() << "success to send  RefreshLog: msg";
	}
	else
	{
		qDebug() << "Client  RefreshLog:";
		qDebug() << "fail to send  RefreshLog: msg";
	}
}

void Chat::onLogRefreshed(QVector<QJsonObject> dataArray)
{
	emit LogRefreshed(dataArray);
}

/**
*Function: onTransferFileButtonClicked
*Description: 点击传输文件按钮后发送消息给服务器，服务器端会初始化传输文件的服务器
*param:
	-username:本机用户名
*/
void Chat::onTransferFileButtonClicked(QString username)
{
	//使用JSON格式传递注册请求
	QJsonObject msg_json;
	msg_json.insert("type", MsgType::preFileTran);
	msg_json.insert("username", username);

	//打包为QJsonDocument格式
	QJsonDocument msg(msg_json);

	//获取facade
	Client* myClient = Client::getInstance();
	myClient->SendMessageToFileServer(msg);

}

/**
*Function: onNewMsgSended
*Description: 用户点击发送或回车后，将消息发送给服务器处理
*param:
	-username:本机用户名
	-peerUsername:对等方用户名
	-content:消息内容
*/
void Chat::onNewMsgSended(QString username, QString targetUsername, QString content)
{
	//使用JSON格式传递注册请求
	QJsonObject msg_json;
	msg_json.insert("type", MsgType::sendMsg);
	msg_json.insert("sender_name", username);
	msg_json.insert("recv_name", targetUsername);
	msg_json.insert("content", content);

	qDebug() << "Client sendMsg:";
	qDebug() << msg_json.value("sender_name");
	qDebug() << msg_json.value("recv_name");
	qDebug() << msg_json.value("content");

	//打包为QJsonDocument格式
	QJsonDocument msg(msg_json);

	//获取facade
	Client* myClient = Client::getInstance();

	//发出请求
	if (myClient->SendMessageToServer(msg))
	{
		qDebug() << "Client sendMsg:";
		qDebug() << "success to send sendMsg msg";
	}
	else
	{
		qDebug() << "Client sendMsg:";
		qDebug() << "fail to send sendMsg msg";
	}
}
