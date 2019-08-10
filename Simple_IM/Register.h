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

public slots:
	void onSignUpSuccess();
	void onSignUpFail(QString info);

private:

signals:
	void SignUpSuccess();
	void SignUpFail(QString info);

};

