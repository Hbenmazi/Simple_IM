#pragma once

#include <QDialog>
#include "ui_LoginGUI.h"
#include "qstring.h"
#include "Login.h"
#include "ListGUI.h"
class Simple_IM;

/**
 * @brief �ͻ��˵�¼����
 */
class LoginGUI : public QDialog
{
	Q_OBJECT

public:
	LoginGUI(QWidget *parent = Q_NULLPTR);
	~LoginGUI();

private:
	Ui::LoginGUI ui;
	Simple_IM* SignUpDialog ; //ע�����
	ListGUI* listDialog;	  //�����б����
	Login login;			  //�������¼����

private slots:
	/**
	*Function: onSignUpButtonClicked
	*Description: ��ת��ע�����
	*/
	void onSignUpButtonClicked();

	/**
	*Function: onSignInButtonClicked
	*Description: �����¼��ť�󽫵�¼��Ϣ���͸�Login�ദ��
	*/
	void onSignInButtonClicked();

	/**
	*Function: onSignInSuccess
	*Description: ��½�ɹ���ʾ�����б�
	*/
	void onSignInSuccess(QString username);

	/**
	*Function: onSignInFail
	*Description: ��½ʧ�ܷ��ش�����Ϣ
	*/
	void onSignInFail(QString info);

};
