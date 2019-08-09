#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Simple_IM.h"
#include "Register.h"
#include "LoginGUI.h"

class Simple_IM : public QMainWindow
{
	Q_OBJECT

public:
	Simple_IM(LoginGUI* LoginDialog, QWidget *parent = Q_NULLPTR);
	~Simple_IM();

private:
	Ui::Simple_IMClass ui;
	LoginGUI* LoginDialog;

private slots:
	void onSignUpButtonClicked();
	void onSignInButtonClicked();
	
};
