#pragma once

#include <QDialog>
#include "ui_LoginGUI.h"
#include "qstring.h"
#include "Login.h"
#include "ListGUI.h"
class Simple_IM;

class LoginGUI : public QDialog
{
	Q_OBJECT

public:
	LoginGUI(QWidget *parent = Q_NULLPTR);
	~LoginGUI();

private:
	Ui::LoginGUI ui;
	Simple_IM* SignUpDialog ;
	ListGUI* listDialog;
	Login login;

private slots:
	void onSignUpButtonClicked();
	void onSignInButtonClicked();
	void onSignInSuccess(QString username);
	void onSignInFail(QString info);

};
