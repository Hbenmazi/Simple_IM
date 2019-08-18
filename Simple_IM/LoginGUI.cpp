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
*Description: 跳转至注册界面
*/
void LoginGUI::onSignUpButtonClicked()
{
	this->close();
	SignUpDialog->show();
}

/**
*Function: onSignInButtonClicked
*Description: 点击登录按钮后将登录信息发送给Login类处理
*/
void LoginGUI::onSignInButtonClicked()
{
	//获取用户名密码
	QString username = ui.username_lineEdit->text();
	QString passward = ui.passward_lineEdit->text();

	//检验是否为空
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

	//不为空则交给 Login类处理
	login.SignIn(username,passward);
}

/**
*Function: onSignInSuccess
*Description: 登陆成功显示好友列表
*/
void LoginGUI::onSignInSuccess(QString username)
{
	listDialog->setUsername(username);
	listDialog->show();
	this->close();
}

/**
*Function: onSignInFail
*Description: 登陆失败返回错误信息
*/
void LoginGUI::onSignInFail(QString info)
{
	ui.Tip_label->setText(info);
}


LoginGUI::~LoginGUI()
{
}
