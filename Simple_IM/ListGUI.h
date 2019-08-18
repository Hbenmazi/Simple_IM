#pragma once

#include <QDialog>
#include "ui_ListGUI.h"
#include "AddGUI.h"
#include "qjsonobject.h"
#include "qvector.h"
#include "ChatGUI.h"
/**
 * @brief 客户端显示好友列表的界面
 */
class ListGUI : public QDialog
{
	Q_OBJECT

public:
	ListGUI(QWidget *parent = Q_NULLPTR);
	~ListGUI();
	void setUsername(QString username);
	QString getUsername() const;

public slots:
	void on_AddButton_clicked();

	/**
	*Function: onListRefreshed
	*Description: 刷新好友列表
	*param:
	*	-userArray:好友列表
	*/
	void onListRefreshed(QVector<QJsonObject> userArray);

	/**
	*Function: onLogRefreshed
	*Description: 更新未读消息条数
	*param:
	*	-dataArray:消息队列
	*/
	void onLogRefreshed(QVector<QJsonObject> dataArray);

private:
	Ui::ListGUI ui;
	AddGUI* addDialog;				 //添加好友的对话框
	ChatGUI* chatDialog;             //聊天对话框
	QString username = "";			 //本机用户名
	QVector<QPushButton*> friendlist;//好友按钮列表


};
