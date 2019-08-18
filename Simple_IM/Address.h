#pragma once
#include <QDialog>
#include "ui_Address.h"
#include <qobject.h>
#include<QMutex>
#include<QString>
#include"qtcpsocket.h"
#include<qhostaddress.h>
#include"LoginGUI.h"
/**
 * @brief �ͻ��˱����������ip��ַ������������˿ںš��ļ�����������˿ںŵ���
 * ����:ʹ�õ���ģʽ�����������ͨ��get������ȡ������Ϣ
 */

class Address : public QDialog
{
	Q_OBJECT

public:
	
	static Address* getInstance();
	void setIp(QString ip);
	void setChatPort(int port);
	void setFilePort(int port);

	QString getServerIp() const;
	int getChatPort() const;
	int getFilePort() const;

private:
	Ui::Address ui;
	static QMutex mutex;
	static Address* m_instance;
	LoginGUI* logingui = NULL;//��¼����
	QString ServerIP = "";
	int chatport = 0;
	int fileport = 0;


	Address(QWidget *parent = Q_NULLPTR);
	~Address();

private slots:

	/**
	*Function: onOkButtonClicked
	*Description: ���ȷ����,���û���д����Ϣ��ʼ������
	*param:
	*/
	void onOkButtonClicked();

signals:
	//void finishSet();
};
