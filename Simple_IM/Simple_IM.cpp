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

/**
*Function: onSignUpButtonClicked
*Description: 获取用户填写的注册信息，初步检验后交给Register类处理
*/
void Simple_IM::onSignUpButtonClicked()
{
	QString username(ui.Username_lineEdit->text());
	QString passward(ui.Passward_lineEdit->text());
	QString passward2(ui.Passward_2_lineEdit->text());
	QString nickname(ui.Nickname_lineEdit->text());
	QString email(ui.Email_lineEdit->text());
	
	//检验各项信息是否为空
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

	//检验两次输入的密码是否相同
	if (passward.compare(passward2))
	{
		ui.Tip_label->setText("passward doesn't match");
		return;
	}

	//检验是否选择头像
	if (profile_index == 0)
	{
		ui.Tip_label->setText("please select a profile");
		return;
	}

	//将注册信息交给Register类处理
	reg.SignUp(username, passward, nickname, email, profile_index);
}

/**
*Function: onSignInButtonClicked
*Description: 跳转至登录界面
*/
void Simple_IM::onSignInButtonClicked()
{
	this->close();
	LoginDialog->show();

}

/**
*Function: onSignUpSuccess
*Description: 注册成功后跳转至登录界面
*/
void Simple_IM::onSignUpSuccess()
{
	onSignInButtonClicked();
}

/**
*Function: onSignUpFail
*Description: 登录失败打印错误信息
*param:
*	-info:服务器返回的错误信息
*/
void Simple_IM::onSignUpFail(QString info)
{
	ui.Tip_label->setText(info);
}

/**
*Function: onSelectButtonClicked
*Description:用户选择头像后记录头像索引
*param:
*	-object_name:头像对象名
*/
void Simple_IM::onSelectButtonClicked(QString object_name)
{
	//记录头像图片索婷
	QString index = object_name.section("_", 1, 1);
	profile_index = index;

	//在注册界面显示头像
	QString file_name = QString("head%1.jpg").arg(index);//头像图片文件名
	ui.profile_label->setStyleSheet("#profile_label{border-image:url(:/Simple_IM/Resources/" + file_name+");}");

}


Simple_IM::~Simple_IM()
{
}


