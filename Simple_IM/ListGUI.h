#pragma once

#include <QDialog>
#include "ui_ListGUI.h"
#include "AddGUI.h"
#include "qjsonobject.h"
#include "qvector.h"
#include "ChatGUI.h"
/**
 * @brief �ͻ�����ʾ�����б�Ľ���
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
	*Description: ˢ�º����б�
	*param:
	*	-userArray:�����б�
	*/
	void onListRefreshed(QVector<QJsonObject> userArray);

	/**
	*Function: onLogRefreshed
	*Description: ����δ����Ϣ����
	*param:
	*	-dataArray:��Ϣ����
	*/
	void onLogRefreshed(QVector<QJsonObject> dataArray);

private:
	Ui::ListGUI ui;
	AddGUI* addDialog;				 //��Ӻ��ѵĶԻ���
	ChatGUI* chatDialog;             //����Ի���
	QString username = "";			 //�����û���
	QVector<QPushButton*> friendlist;//���Ѱ�ť�б�


};
