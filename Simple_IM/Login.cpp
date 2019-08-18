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
*Description: �������������¼����
*param:
	-username:�û���
	-password:����
*return;��������ɹ�������
*/
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

/**
*Function: onSignInSuccess
*Description: ��½�ɹ���ת����Ϣ�����������Ҫ���ʼ�������ļ�������
*param:
	-username:�û���
*/
void Login::onSignInSuccess(QString username)
{
	//ת����½�ɹ���Ϣ
	emit SignInSuccess(username);

	//���������֪����ʼ���ļ����������
	QJsonObject msg_json;
	msg_json.insert("type", MsgType::preFileTran);
	msg_json.insert("username", username);

	//���ΪQJsonDocument��ʽ
	QJsonDocument msg(msg_json);

	//��ȡfacade������
	Client* myClient = Client::getInstance();
	myClient->SendMessageToFileServer(msg);

}
void Login::onSignInFail(QString info)
{
	emit SignInFail(info);
}
