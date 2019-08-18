#pragma once

#include <QDialog>
#include "ui_ChatGUI.h"
#include "qstring.h"
#include "Chat.h"
#include"FileTransfer.h"
#include <QCloseEvent> 
/**
 * @brief �ͻ���������칦�ܵĽ���
 */
class ChatGUI : public QDialog
{
	Q_OBJECT

public:
	ChatGUI(QWidget *parent = Q_NULLPTR,QString username = "");
	~ChatGUI();

	void setUsername(QString username);
	void setPeerUsername(QString peerUsername);

	QString getUsername() const;
	QString getPeerUsername() const;

protected:
	/**
	*Function: closeEvent
	*Description: �����ڹرպ�,ListGUI�϶�Ӧ��ť�ϵ�δ����Ϣ��ʾΪ0
	*/
	void closeEvent(QCloseEvent *event);

	/**
	*Function: eventFilter
	*Description: �¼������������ð��س���������Ϣ
	*/
	bool eventFilter(QObject *obj, QEvent *e);

public slots:
	/**
	*Function: myButtonClicked
	*Description: ���ListGUI�ж�Ӧ�����촰�ڵİ�ť��ˢ�¸ô��ڵ���Ϣ��¼
	*/
	void myButtonClicked();

	/**
	*Function: onNewMsgSended
	*Description: ������Ͱ�ť����Ϣ����Chat����
	*/
	void onNewMsgSended();

	/**
	*Function: onLogRefreshed
	*Description: Chat�����ú���,ˢ�´����е������¼
	*param:
		-dataArray:��Json��ʽ�����������Ϣ����
	*/
	void onLogRefreshed(QVector<QJsonObject> dataArray);

	/**
	*Function: displayLog
	*Description: ��������Ϣ��������촰��
	*param:
		-data:��Json��ʽ�����������Ϣ
	*/
	void displayLog(QJsonObject data);


	void onTransferFileButtonClicked();

	void keyPressEvent(QKeyEvent * event);


private:
	Ui::ChatGUI ui;
	QString username = "";//�����û���
	QString peerUsername = "";//�Եȷ��û���
	Chat* chat;//�������칦��
	FileTransfer* fileTransfer;//�������ļ�����
	QPushButton* myButton;//ListGUI�ж�Ӧ�����촰�ڵİ�ť

signals:
	void NewMsgSended(QString username,QString targetUsername,QString content);
	void LogRefreshed(QVector<QJsonObject> dataArray);

	
};
