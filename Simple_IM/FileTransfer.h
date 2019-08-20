#pragma once

#include <QDialog>
#include "ui_FileTransfer.h"
#include "qfile.h"

/**
 * @brief 作为客户端完成文件传输功能的类
 */
class FileTransfer : public QDialog
{
	Q_OBJECT

public:
	FileTransfer(QString peerUsername = "",QWidget *parent = Q_NULLPTR);
	~FileTransfer();
	void setPeerUsername(QString peerUsername);
	void InitGUI();


public slots:
	void SendHeader();      //传送文件头信息

	/**
	*Function: goOnSend
	*Description: 分片传送实际文件内容
	*param:
	*	numBytes:上一个被发出的文件分片的字节数
	*/
	void goOnSend(qint64 numBytes);  //传送文件内容
	void onOpenPushButtonClicked();
	void onSendPushButtonClicked();
	void onFileSocketReadyRead(QByteArray data);
	
private:
	Ui::FileTransfer ui;
	QString peerUsername;//接收方用户名
	QFile *localFile;
	QString fileName;  //文件路径

	/*以下是作为发送端需要的属性*/
	QByteArray outBlock;  //分次传的缓冲区
	qint64 loadSize;      //每次发送数据的大小
	qint64 byteToWrite;   //剩余数据大小
	qint64 totalSize_out; //文件总大小

	/*以下是作为接收端需要的属性*/
	QFile *newFile;
	QByteArray inBlock;	  //分次接收缓冲区
	QString fileName_in;  //接收文件的路径
	qint64 totalSize_in;  //总共需要发送的文件大小（文件内容&文件名信息）
	qint64 byteReceived;  //已经发送的大小


};
