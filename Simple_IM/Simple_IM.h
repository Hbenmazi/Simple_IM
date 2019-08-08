#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Simple_IM.h"
#include "Register.h"


class Simple_IM : public QMainWindow
{
	Q_OBJECT

public:
	Simple_IM(QWidget *parent = Q_NULLPTR);

private:
	Ui::Simple_IMClass ui;

	void on_SignUpButton_clicked();
	
};
