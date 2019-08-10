#include "Register.h"
#include "User.h"
#include "qjsonvalue.h"
#include "qjsonobject.h"
#include "qjsondocument.h"
#include "Client.h"
#include "MsgType.h"
Register::Register()
{

}


Register::~Register()
{
}

/**
*Function: Register::SignUp
*Description: ���û�ע��
*param:
*username - �û���
*passward - ����
*nickname - ����
*email - ��������
*return: ע��ɹ��򷵻���
*/
bool Register::SignUp(QString username, QString password, QString nickname, QString email) const
{
	//ʹ��JSON��ʽ����ע������
	QJsonObject msg_json;
	msg_json.insert("type",MsgType::signup);//type�ֶ�����Ϊsignup��������ͨ��tyoe�ֶ�������Ҫ���Ĳ���
	msg_json.insert("username", username);
	msg_json.insert("password", password);
	msg_json.insert("nickname", nickname);
	msg_json.insert("email", email);

	qDebug() << "Client Sign up:";
	qDebug() << msg_json.value("username");
	qDebug() << msg_json.value("password");
	qDebug() << msg_json.value("nickname");
	qDebug() << msg_json.value("email");

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