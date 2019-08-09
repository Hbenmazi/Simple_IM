#include "LoginGUI.h"
#include "Simple_IM.h"
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
	
}


LoginGUI::~LoginGUI()
{
}
