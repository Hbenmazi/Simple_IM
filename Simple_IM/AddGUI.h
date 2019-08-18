#pragma once

#include <QDialog>
#include "ui_AddGUI.h"
#include "Add.h"
#include "qjsonobject.h"

/**
 * @brief �ͻ�����Ӻ��ѵĽ���
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
	*Description: �����ť�󴥷�,���û���д����Ϣ����Add�ദ��
	*/
	void on_AddButton_clicked();

	/**
	*Function: onAddContactSuccess
	*Description: �յ���ӳɹ����źź󣬽���Ϣ��ӡ������
	*param:
		-data:�������˷��صĳɹ���Ϣ
	*/
	void onAddContactSuccess(QJsonObject data);

	/**
	*Function: onAddContactFail
	*Description: �յ����ʧ�ܵ��źź󣬽���Ϣ��ӡ������
	*param:
		-data:�������˷��صĴ�����Ϣ
	*/
	void onAddContactFail(QJsonObject data);

private:
	Ui::AddGUI ui;
	Add add;

};
