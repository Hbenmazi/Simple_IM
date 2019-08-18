#pragma once
#include <qobject.h>
/**
 * @brief 客户端完成注册功能的类
 */

class Register :public QObject
{
	Q_OBJECT
public:
	Register();
	~Register();

	/**
	*Function: SignUp
	*Description: 向服务器发送注册请求
	*param:
	*	-username:     用户名
	*	-passward:     密码
	*	-nickname:     昵称
	*	-emial:	       电子邮箱
	*	-profile_index:头像图片索引
	*return:登陆成功返回真
	*/
	bool SignUp(QString username, QString password, QString nickname, QString email,QString profile_index) const;

public slots:
	/**
	*Function: onSignUpSuccess
	*Description: 转发登陆成功消息
	*/
	void onSignUpSuccess();

	/**
	*Function: onSignUpFail
	*Description: 转发登陆失败消息
	*Param:
	*	-info:服务器端返回的错误信息
	*/
	void onSignUpFail(QString info);

private:

signals:
	void SignUpSuccess();
	void SignUpFail(QString info);

};

