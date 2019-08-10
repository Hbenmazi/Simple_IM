#include "LoginGUI.h"
#include "Simple_IM.h"
#include "Login.h"
LoginGUI::LoginGUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	SignUpDialog = new Simple_IM(this);

	connect(ui.SignUp_pushButton, &QPushButton::clicked, this, &LoginGUI::onSignUpButtonClicked);
	connect(ui.SignIn_pushButton, &QPushButton::clicked, this, &LoginGUI::onSignInButtonClicked);
}


void LoginGUI::onSignUpButtonClicked()
{
	this->close();
	SignUpDialog->show();
}

void LoginGUI::onSignInButtonClicked()
{
	Login login;
	QString username = ui.username_lineEdit->text();
	QString passward = ui.passward_lineEdit->text();

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

	login.SignIn(username,passward);
}


LoginGUI::~LoginGUI()
{
}
