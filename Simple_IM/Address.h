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
 * @brief 客户端保存服务器的ip地址、聊天服务器端口号、文件传输服务器端口号的类
 * 描述:使用单例模式，其它类可以通过get函数获取上述信息
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
	LoginGUI* logingui = NULL;//登录界面
	QString ServerIP = "";
	int chatport = 0;
	int fileport = 0;


	Address(QWidget *parent = Q_NULLPTR);
	~Address();

private slots:

	/**
	*Function: onOkButtonClicked
	*Description: 点击确定后,用用户填写的信息初始化改类
	*param:
	*/
	void onOkButtonClicked();

signals:
	//void finishSet();
};
