#include "LoginGUI.h"
#include "Simple_IM.h"
#include "Login.h"
#include "List.h"
LoginGUI::LoginGUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	SignUpDialog = new Simple_IM(this);
	listDialog = new ListGUI();

	connect(ui.SignUp_pushButton, &QPushButton::clicked, this, &LoginGUI::onSignUpButtonClicked);
	connect(ui.SignIn_pushButton, &QPushButton::clicked, this, &LoginGUI::onSignInButtonClicked);
	connect(&login, SIGNAL(SignInSuccess(QString)), this, SLOT(onSignInSuccess(QString)));
	connect(&login, SIGNAL(SignInFail(QString)), this, SLOT(onSignInFail(QString)));
}

/**
*Function: onSignUpButtonClicked
*Description: ��ת��ע�����
*/
void LoginGUI::onSignUpButtonClicked()
{
	this->close();
	SignUpDialog->show();
}

/**
*Function: onSignInButtonClicked
*Description: �����¼��ť�󽫵�¼��Ϣ���͸�Login�ദ��
*/
void LoginGUI::onSignInButtonClicked()
{
	//��ȡ�û�������
	QString username = ui.username_lineEdit->text();
	QString passward = ui.passward_lineEdit->text();

	//�����Ƿ�Ϊ��
	if (username.isEmpty())
	{
		ui.Tip_label->setText("username can't be empty");
		return ;
	}
	if (passward.isEmpty())
	{
		ui.Tip_label->setText("passward can't be empty");
		return ;
	}

	//��Ϊ���򽻸� Login�ദ��
	login.SignIn(username,passward);
}

/**
*Function: onSignInSuccess
*Description: ��½�ɹ���ʾ�����б�
*/
void LoginGUI::onSignInSuccess(QString username)
{
	listDialog->setUsername(username);
	listDialog->show();
	this->close();
}

/**
*Function: onSignInFail
*Description: ��½ʧ�ܷ��ش�����Ϣ
*/
void LoginGUI::onSignInFail(QString info)
{
	ui.Tip_label->setText(info);
}


LoginGUI::~LoginGUI()
{
}
