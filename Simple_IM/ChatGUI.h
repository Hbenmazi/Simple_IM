#pragma once

#include <QDialog>
#include "ui_ChatGUI.h"
#include "qstring.h"
#include "Chat.h"
#include"FileTransfer.h"
#include <QCloseEvent> 
/**
 * @brief 客户端完成聊天功能的界面
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
	*Description: 将窗口关闭后,ListGUI上对应按钮上的未读消息显示为0
	*/
	void closeEvent(QCloseEvent *event);

	/**
	*Function: eventFilter
	*Description: 事件过滤器，设置按回车键发送消息
	*/
	bool eventFilter(QObject *obj, QEvent *e);

public slots:
	/**
	*Function: myButtonClicked
	*Description: 点击ListGUI中对应该聊天窗口的按钮后，刷新该窗口的消息记录
	*/
	void myButtonClicked();

	/**
	*Function: onNewMsgSended
	*Description: 点击发送按钮后将消息交给Chat处理
	*/
	void onNewMsgSended();

	/**
	*Function: onLogRefreshed
	*Description: Chat触发该函数,刷新窗口中的聊天记录
	*param:
		-dataArray:以Json格式储存的聊天消息向量
	*/
	void onLogRefreshed(QVector<QJsonObject> dataArray);

	/**
	*Function: displayLog
	*Description: 将单条消息输出到聊天窗口
	*param:
		-data:以Json格式储存的聊天消息
	*/
	void displayLog(QJsonObject data);


	void onTransferFileButtonClicked();

	void keyPressEvent(QKeyEvent * event);


private:
	Ui::ChatGUI ui;
	QString username = "";//本机用户名
	QString peerUsername = "";//对等方用户名
	Chat* chat;//负责聊天功能
	FileTransfer* fileTransfer;//负责传输文件功能
	QPushButton* myButton;//ListGUI中对应该聊天窗口的按钮

signals:
	void NewMsgSended(QString username,QString targetUsername,QString content);
	void LogRefreshed(QVector<QJsonObject> dataArray);

	
};
