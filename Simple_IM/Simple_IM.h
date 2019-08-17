#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Simple_IM.h"
#include "Register.h"
#include "LoginGUI.h"
#include "ProfileGUI.h"
class Simple_IM : public QMainWindow
{
	Q_OBJECT

public:
	Simple_IM(LoginGUI* LoginDialog, QWidget *parent = Q_NULLPTR);
	~Simple_IM();

private:
	Ui::Simple_IMClass ui;
	LoginGUI* LoginDialog;
	ProfileGUI* profile;
	Register reg;
	QString profile_index = 0;

private slots:
	void onSignUpButtonClicked();
	void onSignInButtonClicked();
	void onSignUpSuccess();
	void onSignUpFail(QString info);
	void onSelectButtonClicked(QString);
};
