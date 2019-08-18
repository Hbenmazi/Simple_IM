#pragma once

#include <QDialog>
#include "ui_ProfileGUI.h"

/**
 * @brief 客户端选择头像界面
 */
class ProfileGUI : public QDialog
{
	Q_OBJECT

public:
	ProfileGUI(QWidget *parent = Q_NULLPTR);
	~ProfileGUI();

private:
	Ui::ProfileGUI ui;

private slots:
	//发送用户选择头像图片的对象名称
	void onSelectButtonClicked();

signals:
	void SelectButtonClicked(QString name);
};
