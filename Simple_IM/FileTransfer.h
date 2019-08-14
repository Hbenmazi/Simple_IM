#pragma once

#include <QDialog>
#include "ui_FileTransfer.h"
#include "qfile.h"

class FileTransfer : public QDialog
{
	Q_OBJECT

public:
	FileTransfer(QString peerUsername = "",QWidget *parent = Q_NULLPTR);
	~FileTransfer();
	void setPeerUsername(QString peerUsername);

	QFile *localFile;
	QString fileName;  //文件名

	/*以下是作为发送端需要的属性*/
	QByteArray outBlock;  //分次传
	qint64 loadSize;  //每次发送数据的大小
	qint64 byteToWrite;  //剩余数据大小
	qint64 totalSize_out;  //文件总大小
	int sendTimes;  //用来标记是否为第一次发送，第一次以后连接信号触发，后面的则手动调

	/*以下是作为接收端需要的属性*/
	QFile *newFile;
	QByteArray inBlock;
	QString fileName_in;
	qint64 totalSize_in;  //总共需要发送的文件大小（文件内容&文件名信息）
	qint64 byteReceived;  //已经发送的大小



public slots:
	void SendHeader();  //传送文件头信息
	void goOnSend(qint64);  //传送文件内容
	void onOpenPushButtonClicked();
	void onSendPushButtonClicked();
	void onFileSocketReadyRead(QByteArray data);
private:
	Ui::FileTransfer ui;
	QString peerUsername;


};
