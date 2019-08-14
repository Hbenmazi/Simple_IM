#pragma once
#include "qobject.h"
#include"qvector.h"
#include"qjsonobject.h"
class Chat :public QObject
{
	Q_OBJECT

public:
	Chat();
	~Chat();

	void RefreshLog(QString username, QString peerUsername);

public slots:
	void onNewMsgSended(QString username, QString targetUsername, QString content);
	void onLogRefreshed(QVector<QJsonObject> dataArray);
	void onTransferFileButtonClicked(QString username);
	
signals:
	void LogRefreshed(QVector<QJsonObject> dataArray);

};

