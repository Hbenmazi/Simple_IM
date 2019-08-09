#pragma once
#include <qobject.h>
/**
 * @brief 完成注册功能的类
 */

class Register :public QObject
{
	Q_OBJECT
public:
	Register();
	~Register();

	bool SignUp(QString username, QString password, QString naickname, QString email) const;


};

