#pragma once

#include <QDialog>
#include "ui_ProfileGUI.h"

class ProfileGUI : public QDialog
{
	Q_OBJECT

public:
	ProfileGUI(QWidget *parent = Q_NULLPTR);
	~ProfileGUI();

private:
	Ui::ProfileGUI ui;

private slots:
	void onSelectButtonClicked();

signals:
	void SelectButtonClicked(QString name);
};
