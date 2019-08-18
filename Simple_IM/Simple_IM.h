#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Simple_IM.h"
#include "Register.h"
#include "LoginGUI.h"
#include "ProfileGUI.h"
/**
 * @brief �ͻ���ע�����
 */
class Simple_IM : public QMainWindow
{
	Q_OBJECT

public:
	Simple_IM(LoginGUI* LoginDialog, QWidget *parent = Q_NULLPTR);
	~Simple_IM();

private:
	Ui::Simple_IMClass ui;
	LoginGUI* LoginDialog;		//��¼����
	ProfileGUI* profile;		//ѡ��ͷ�񴰿�
	Register reg;			    //�����¼����
	QString profile_index = 0;	//ͷ������

private slots:
	/**
	*Function: onSignUpButtonClicked
	*Description: ��ȡ�û���д��ע����Ϣ����������󽻸�Register�ദ��
	*/
	void onSignUpButtonClicked();

	/**
	*Function: onSignInButtonClicked
	*Description: ��ת����¼����
	*/
	void onSignInButtonClicked();

	/**
	*Function: onSignUpSuccess
	*Description: ע��ɹ�����ת����¼����
	*/
	void onSignUpSuccess();

	/**
	*Function: onSignUpFail
	*Description: ��¼ʧ�ܴ�ӡ������Ϣ
	*param:
	*	-info:���������صĴ�����Ϣ
	*/
	void onSignUpFail(QString info);

	/**
	*Function: onSelectButtonClicked
	*Description:�û�ѡ��ͷ����¼ͷ������
	*param:
	*	-object_name:ͷ�������
	*/
	void onSelectButtonClicked(QString object_name);
};
