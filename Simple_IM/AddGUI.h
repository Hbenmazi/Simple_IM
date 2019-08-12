#pragma once

#include <QDialog>
#include "ui_AddGUI.h"
#include "Add.h"
#include "qjsonobject.h"
class AddGUI : public QDialog
{
	Q_OBJECT

public:
	AddGUI(QWidget *parent = Q_NULLPTR);
	~AddGUI();

public slots:
	void on_AddButton_clicked();
	void onAddContactSuccess(QJsonObject data);
	void onAddContactFail(QJsonObject data);

private:
	Ui::AddGUI ui;
	Add add;

};
