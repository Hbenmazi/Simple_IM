#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Simple_IM.h"
#include "Register.h"
#include "LoginGUI.h"
#include "ProfileGUI.h"
/**
 * @brief 客户端注册界面
 */
class Simple_IM : public QMainWindow
{
	Q_OBJECT

public:
	Simple_IM(LoginGUI* LoginDialog, QWidget *parent = Q_NULLPTR);
	~Simple_IM();

private:
	Ui::Simple_IMClass ui;
	LoginGUI* LoginDialog;		//登录窗口
	ProfileGUI* profile;		//选择头像窗口
	Register reg;			    //处理登录功能
	QString profile_index = 0;	//头像索引

private slots:
	/**
	*Function: onSignUpButtonClicked
	*Description: 获取用户填写的注册信息，初步检验后交给Register类处理
	*/
	void onSignUpButtonClicked();

	/**
	*Function: onSignInButtonClicked
	*Description: 跳转至登录界面
	*/
	void onSignInButtonClicked();

	/**
	*Function: onSignUpSuccess
	*Description: 注册成功后跳转至登录界面
	*/
	void onSignUpSuccess();

	/**
	*Function: onSignUpFail
	*Description: 登录失败打印错误信息
	*param:
	*	-info:服务器返回的错误信息
	*/
	void onSignUpFail(QString info);

	/**
	*Function: onSelectButtonClicked
	*Description:用户选择头像后记录头像索引
	*param:
	*	-object_name:头像对象名
	*/
	void onSelectButtonClicked(QString object_name);
};
