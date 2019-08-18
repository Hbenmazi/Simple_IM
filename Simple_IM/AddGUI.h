#pragma once

#include <QDialog>
#include "ui_AddGUI.h"
#include "Add.h"
#include "qjsonobject.h"

/**
 * @brief 客户端添加好友的界面
 */
class AddGUI : public QDialog
{
	Q_OBJECT

public:
	AddGUI(QWidget *parent = Q_NULLPTR);
	~AddGUI();

public slots:

	/**
	*Function: on_AddButton_clicked
	*Description: 点击按钮后触发,将用户填写的信息交给Add类处理
	*/
	void on_AddButton_clicked();

	/**
	*Function: onAddContactSuccess
	*Description: 收到添加成功的信号后，将信息打印到界面
	*param:
		-data:服务器端返回的成功信息
	*/
	void onAddContactSuccess(QJsonObject data);

	/**
	*Function: onAddContactFail
	*Description: 收到添加失败的信号后，将信息打印到界面
	*param:
		-data:服务器端返回的错误信息
	*/
	void onAddContactFail(QJsonObject data);

private:
	Ui::AddGUI ui;
	Add add;

};
