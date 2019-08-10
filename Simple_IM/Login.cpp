#include "Login.h"
#include"qjsonobject.h"
#include"qjsondocument.h"
#include"MsgType.h"
#include "Client.h"
Login::Login()
{
}


Login::~Login()
{
}

bool Login::SignIn(QString username, QString password) const
{
	//ʹ��JSON��ʽ����ע������
	QJsonObject msg_json;
	msg_json.insert("type", MsgType::signin);//type�ֶ�����Ϊsignup��������ͨ��type�ֶ�������Ҫ���Ĳ���
	msg_json.insert("username", username);
	msg_json.insert("password", password);

	qDebug() << "Client Sign in:";
	qDebug() << msg_json.value("username");
	qDebug() << msg_json.value("password");

	//���ΪQJsonDocument��ʽ
	QJsonDocument msg(msg_json);

	//��ȡfacade
	Client* myClient = Client::getInstance();

	//��������
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
