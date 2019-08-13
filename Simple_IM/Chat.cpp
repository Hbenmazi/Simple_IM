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

///TODOTODOTODOTODOTODOODODODODODODODOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
void Chat::onNewMsgSended(QString username, QString targetUsername, QString content)
{

}
