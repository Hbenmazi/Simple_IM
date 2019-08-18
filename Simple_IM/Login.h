#pragma once
#include <qobject.h>
#include"qstring.h"
/**
 * @brief �ͻ��˴����¼���ܵ���
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
	*Description: �������������¼����
	*param:
		-username:�û���
		-password:����
	*return;��������ɹ�������
	*/
	bool SignIn(QString username, QString password) const;

public slots:
	/**
	*Function: onSignInSuccess
	*Description: ��½�ɹ���ת����Ϣ�����������Ҫ���ʼ�������ļ�������
	*param:
		-username:�û���
	*/
	void onSignInSuccess(QString username);

	/**
	*Function: onSignInFail
	*Description: ��½ʧ�ܺ�ת����Ϣ
	*param:
		-info:�������˷��صĵ�¼������Ϣ
	*/
	void onSignInFail(QString info);

signals:
	void SignInSuccess(QString username);
	void SignInFail(QString info);

};

