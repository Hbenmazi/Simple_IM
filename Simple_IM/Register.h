#pragma once
#include <qobject.h>
/**
 * @brief ���ע�Ṧ�ܵ���
 */

class Register :public QObject
{
	Q_OBJECT
public:
	Register();
	~Register();

	bool SignUp(QString username, QString password, QString naickname, QString email) const;


};

