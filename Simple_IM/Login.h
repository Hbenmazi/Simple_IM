#pragma once
#include <qobject.h>
#include"qstring.h"
/**
 * @brief 客户端处理登录功能的类
 */
class Login :
	public QObject
{
	Q_OBJECT
public:
	Login();
	~Login();

	/**
	*Function: SignIn
	*Description: 向服务器发出登录请求
	*param:
		-username:用户名
		-password:密码
	*return;发出请求成功返回真
	*/
	bool SignIn(QString username, QString password) const;

public slots:
	/**
	*Function: onSignInSuccess
	*Description: 登陆成功后转发消息，并向服务器要求初始化传输文件服务器
	*param:
		-username:用户名
	*/
	void onSignInSuccess(QString username);

	/**
	*Function: onSignInFail
	*Description: 登陆失败后转发消息
	*param:
		-info:服务器端返回的登录错误信息
	*/
	void onSignInFail(QString info);

signals:
	void SignInSuccess(QString username);
	void SignInFail(QString info);

};

