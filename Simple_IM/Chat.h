#pragma once
#include "qobject.h"
#include"qvector.h"
#include"qjsonobject.h"
/**
 * @brief 客户端完成聊天功能的类
 * 描述:将客户端发来的消息更新到聊天窗口,将用户发送的消息发送给服务器处理
 */
class Chat :public QObject
{
	Q_OBJECT

public:
	Chat();
	~Chat();

	/**
	*Function: RefreshLog
	*Description: 向服务器提交刷新聊天窗口的请求
	*param:
		-username:本机用户名
		-peerUsername:对等方用户名
	*/
	void RefreshLog(QString username, QString peerUsername);

public slots:
	/**
	*Function: onNewMsgSended
	*Description: 用户点击发送或回车后，将消息发送给服务器处理
	*param:
		-username:本机用户名
		-peerUsername:对等方用户名
		-content:消息内容
	*/
	void onNewMsgSended(QString username, QString targetUsername, QString content);

	/**
	*Function: onLogRefreshed
	*Description: 收到服务器传送的聊天记录后，发送 LogRefreshed信号，交给ChatGUI
	*param:
		-dataArray:以Json格式储存的消息向量
	*/
	void onLogRefreshed(QVector<QJsonObject> dataArray);

	/**
	*Function: onTransferFileButtonClicked
	*Description: 点击传输文件按钮后发送消息给服务器，服务器端会初始化传输文件的服务器
	*param:
		-username:本机用户名
	*/
	void onTransferFileButtonClicked(QString username);
	
signals:
	void LogRefreshed(QVector<QJsonObject> dataArray);

};

