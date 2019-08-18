#pragma once

#include <QDialog>
#include "ui_ProfileGUI.h"

/**
 * @brief �ͻ���ѡ��ͷ�����
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
	//�����û�ѡ��ͷ��ͼƬ�Ķ�������
	void onSelectButtonClicked();

signals:
	void SelectButtonClicked(QString name);
};
