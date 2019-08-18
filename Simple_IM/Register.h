#pragma once
#include <qobject.h>
/**
 * @brief �ͻ������ע�Ṧ�ܵ���
 */

class Register :public QObject
{
	Q_OBJECT
public:
	Register();
	~Register();

	/**
	*Function: SignUp
	*Description: �����������ע������
	*param:
	*	-username:     �û���
	*	-passward:     ����
	*	-nickname:     �ǳ�
	*	-emial:	       ��������
	*	-profile_index:ͷ��ͼƬ����
	*return:��½�ɹ�������
	*/
	bool SignUp(QString username, QString password, QString nickname, QString email,QString profile_index) const;

public slots:
	/**
	*Function: onSignUpSuccess
	*Description: ת����½�ɹ���Ϣ
	*/
	void onSignUpSuccess();

	/**
	*Function: onSignUpFail
	*Description: ת����½ʧ����Ϣ
	*Param:
	*	-info:�������˷��صĴ�����Ϣ
	*/
	void onSignUpFail(QString info);

private:

signals:
	void SignUpSuccess();
	void SignUpFail(QString info);

};

