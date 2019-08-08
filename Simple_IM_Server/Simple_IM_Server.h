#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Simple_IM_Server.h"

class Simple_IM_Server : public QMainWindow
{
	Q_OBJECT

public:
	Simple_IM_Server(QWidget *parent = Q_NULLPTR);

private:
	Ui::Simple_IM_ServerClass ui;
};
