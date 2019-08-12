#pragma once

#include <QDialog>
#include "ui_ListGUI.h"
#include "AddGUI.h"
#include "qjsonobject.h"
#include "qvector.h"
#include "ChatGUI.h"
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
	void onListRefreshed(QVector<QJsonObject> userArray);

private:
	Ui::ListGUI ui;
	AddGUI* add;//��Ӻ��ѵĶԻ���
	ChatGUI* chat;//����Ի���
	QString username = "";
	QVector<QPushButton*> friendlist;


};
