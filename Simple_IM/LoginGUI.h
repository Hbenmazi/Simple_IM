#pragma once

#include <QDialog>
#include "ui_LoginGUI.h"
#include "qstring.h"
#include "Login.h"
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

	Login login;

private slots:
	void onSignUpButtonClicked();
	void onSignInButtonClicked();
	void onSignInSuccess();
	void onSignInFail(QString info);

};
