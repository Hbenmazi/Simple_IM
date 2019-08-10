#include "Simple_IM.h"

Simple_IM::Simple_IM(LoginGUI* LoginD, QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	LoginDialog = LoginD;
	QObject::connect(ui.SignUp_pushButton,&QPushButton::clicked,this,&Simple_IM::onSignUpButtonClicked);
	QObject::connect(ui.SignIn_pushButton, &QPushButton::clicked, this, &Simple_IM::onSignInButtonClicked);
	QObject::connect(&reg, SIGNAL(SignUpSuccess()), this, SLOT(onSignUpSuccess()));
	QObject::connect(&reg, SIGNAL(SignUpFail(QString)), this, SLOT(onSignUpFail(QString)));
}

void Simple_IM::onSignUpButtonClicked()
{
	QString username(ui.Username_lineEdit->text());
	QString passward(ui.Passward_lineEdit->text());
	QString passward2(ui.Passward_2_lineEdit->text());
	QString nickname(ui.Nickname_lineEdit->text());
	QString email(ui.Email_lineEdit->text());
	
	if (username.size() == 0)
	{
		ui.Tip_label->setText("username can't be empty");
		return;
	}

	if (passward.size() == 0)
	{
		ui.Tip_label->setText("passward can't be empty");
		return;
	}

	if (passward2.size() == 0)
	{
		ui.Tip_label->setText("passward2 can't be empty");
		return ;
	}

	if (nickname.size() == 0)
	{
		ui.Tip_label->setText("nickname can't be empty");
		return;
	}

	if (email.size() == 0)
	{
		ui.Tip_label->setText("eamil can't be empty");
		return;
	}

	if (passward.compare(passward2))
	{
		ui.Tip_label->setText("passward doesn't match");
		return;
	}

	reg.SignUp(username, passward, nickname, email);
	

}

void Simple_IM::onSignInButtonClicked()
{
	this->close();
	LoginDialog->show();

}

void Simple_IM::onSignUpSuccess()
{
	onSignInButtonClicked();
}

void Simple_IM::onSignUpFail(QString info)
{
	ui.Tip_label->setText(info);
}

Simple_IM::~Simple_IM()
{
}


