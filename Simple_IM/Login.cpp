#include "Login.h"
#include"qjsonobject.h"
#include"qjsondocument.h"
#include"MsgType.h"
#include "Client.h"
Login::Login()
{
	connect(Client::getInstance(), SIGNAL(SignInSuccess()), this, SLOT(onSignInSuccess()));
	connect(Client::getInstance(), SIGNAL(SignInFail(QString)), this, SLOT(onSignInFail(QString)));
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

void Login::onSignInSuccess()
{
	emit SignInSuccess();
}
void Login::onSignInFail(QString info)
{
	emit SignInFail(info);
}
