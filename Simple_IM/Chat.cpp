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
*Description: ��������ύˢ�����촰�ڵ�����
*param:
	-username:�����û���
	-peerUsername:�Եȷ��û���
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

	//���ΪQJsonDocument��ʽ
	QJsonDocument msg(msg_json);

	//��ȡfacade
	Client* myClient = Client::getInstance();

	//��������
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
*Description: ��������ļ���ť������Ϣ�����������������˻��ʼ�������ļ��ķ�����
*param:
	-username:�����û���
*/
void Chat::onTransferFileButtonClicked(QString username)
{
	//ʹ��JSON��ʽ����ע������
	QJsonObject msg_json;
	msg_json.insert("type", MsgType::preFileTran);
	msg_json.insert("username", username);

	//���ΪQJsonDocument��ʽ
	QJsonDocument msg(msg_json);

	//��ȡfacade
	Client* myClient = Client::getInstance();
	myClient->SendMessageToFileServer(msg);

}

/**
*Function: onNewMsgSended
*Description: �û�������ͻ�س��󣬽���Ϣ���͸�����������
*param:
	-username:�����û���
	-peerUsername:�Եȷ��û���
	-content:��Ϣ����
*/
void Chat::onNewMsgSended(QString username, QString targetUsername, QString content)
{
	//ʹ��JSON��ʽ����ע������
	QJsonObject msg_json;
	msg_json.insert("type", MsgType::sendMsg);
	msg_json.insert("sender_name", username);
	msg_json.insert("recv_name", targetUsername);
	msg_json.insert("content", content);

	qDebug() << "Client sendMsg:";
	qDebug() << msg_json.value("sender_name");
	qDebug() << msg_json.value("recv_name");
	qDebug() << msg_json.value("content");

	//���ΪQJsonDocument��ʽ
	QJsonDocument msg(msg_json);

	//��ȡfacade
	Client* myClient = Client::getInstance();

	//��������
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
