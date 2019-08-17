#include "Simple_IM.h"

Simple_IM::Simple_IM(LoginGUI* LoginD, QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	LoginDialog = LoginD;
	ProfileGUI* profile = new ProfileGUI(this);
	QObject::connect(ui.SignUp_pushButton,&QPushButton::clicked,this,&Simple_IM::onSignUpButtonClicked);
	QObject::connect(ui.SignIn_pushButton, &QPushButton::clicked, this, &Simple_IM::onSignInButtonClicked);
	QObject::connect(ui.select_pushButton, &QPushButton::clicked, profile,&ProfileGUI::show);
	QObject::connect(&reg, SIGNAL(SignUpSuccess()), this, SLOT(onSignUpSuccess()));
	QObject::connect(&reg, SIGNAL(SignUpFail(QString)), this, SLOT(onSignUpFail(QString)));
	QObject::connect(profile, SIGNAL(SelectButtonClicked(QString)), this, SLOT(onSelectButtonClicked(QString)));
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

	if (profile_index == 0)
	{
		ui.Tip_label->setText("please select a profile");
		return;
	}

	reg.SignUp(username, passward, nickname, email, profile_index);
	

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

void Simple_IM::onSelectButtonClicked(QString object_name)
{
	QString index = object_name.section("_", 1, 1);
	profile_index = index;
	QString file_name = QString("head%1.jpg").arg(index);
	ui.profile_label->setStyleSheet("#profile_label{border-image:url(:/Simple_IM/Resources/" + file_name+");}");

}


Simple_IM::~Simple_IM()
{
}


