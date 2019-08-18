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
*Description: �����������ע������
*param:
*	-username:     �û���
*	-passward:     ����
*	-nickname:     �ǳ�
*	-emial:	       ��������
*	-profile_index:ͷ��ͼƬ����
*return:��½�ɹ�������
*/
bool Register::SignUp(QString username, QString password, QString nickname, QString email, QString profile_index) const
{
	//ʹ��JSON��ʽ����ע������
	QJsonObject msg_json;
	msg_json.insert("type",MsgType::signup);//type�ֶ�����Ϊsignup��������ͨ��tyoe�ֶ�������Ҫ���Ĳ���
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

	//���ΪQJsonDocument��ʽ
	QJsonDocument msg(msg_json);

	//��ȡfacade
	Client* myClient = Client::getInstance();


	//��������
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
