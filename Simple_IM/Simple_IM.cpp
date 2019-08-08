#include "Simple_IM.h"

Simple_IM::Simple_IM(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.SignUp_pushButton,&QPushButton::clicked,this,&Simple_IM::on_SignUpButton_clicked);
}

void Simple_IM::on_SignUpButton_clicked()
{
	Register reg;
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

	if (!passward.compare(passward2))
	{
		ui.Tip_label->setText("passward doesn't match");
		return;
	}

	if(reg.SignUp(username, passward, nickname, email))
		ui.Tip_label->setText("Sign up successfully");
	else
		ui.Tip_label->setText("username has already existed");

}
