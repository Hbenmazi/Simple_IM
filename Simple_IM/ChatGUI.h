#pragma once

#include <QDialog>
#include "ui_ChatGUI.h"
#include "qstring.h"
#include "Chat.h"
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

public slots:
	void myButtonClicked();
	void onNewMsgSended();
	void onLogRefreshed(QVector<QJsonObject> dataArray);
	void displayLog(QJsonObject data);

private:
	Ui::ChatGUI ui;
	QString username = "";
	QString peerUsername = "";
	Chat* chat;

signals:
	void NewMsgSended(QString username,QString targetUsername,QString content);

	
};
