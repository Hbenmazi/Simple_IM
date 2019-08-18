#pragma once

#include <QDialog>
#include "ui_LoginGUI.h"
#include "qstring.h"
#include "Login.h"
#include "ListGUI.h"
class Simple_IM;

/**
 * @brief 客户端登录界面
 */
class LoginGUI : public QDialog
{
	Q_OBJECT

public:
	LoginGUI(QWidget *parent = Q_NULLPTR);
	~LoginGUI();

private:
	Ui::LoginGUI ui;
	Simple_IM* SignUpDialog ; //注册界面
	ListGUI* listDialog;	  //好友列表界面
	Login login;			  //负责处理登录功能

private slots:
	/**
	*Function: onSignUpButtonClicked
	*Description: 跳转至注册界面
	*/
	void onSignUpButtonClicked();

	/**
	*Function: onSignInButtonClicked
	*Description: 点击登录按钮后将登录信息发送给Login类处理
	*/
	void onSignInButtonClicked();

	/**
	*Function: onSignInSuccess
	*Description: 登陆成功显示好友列表
	*/
	void onSignInSuccess(QString username);

	/**
	*Function: onSignInFail
	*Description: 登陆失败返回错误信息
	*/
	void onSignInFail(QString info);

};
