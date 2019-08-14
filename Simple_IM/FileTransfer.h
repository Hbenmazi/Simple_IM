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
	QString fileName;  //�ļ���

	/*��������Ϊ���Ͷ���Ҫ������*/
	QByteArray outBlock;  //�ִδ�
	qint64 loadSize;  //ÿ�η������ݵĴ�С
	qint64 byteToWrite;  //ʣ�����ݴ�С
	qint64 totalSize_out;  //�ļ��ܴ�С
	int sendTimes;  //��������Ƿ�Ϊ��һ�η��ͣ���һ���Ժ������źŴ�������������ֶ���

	/*��������Ϊ���ն���Ҫ������*/
	QFile *newFile;
	QByteArray inBlock;
	QString fileName_in;
	qint64 totalSize_in;  //�ܹ���Ҫ���͵��ļ���С���ļ�����&�ļ�����Ϣ��
	qint64 byteReceived;  //�Ѿ����͵Ĵ�С



public slots:
	void SendHeader();  //�����ļ�ͷ��Ϣ
	void goOnSend(qint64);  //�����ļ�����
	void onOpenPushButtonClicked();
	void onSendPushButtonClicked();
	void onFileSocketReadyRead(QByteArray data);
private:
	Ui::FileTransfer ui;
	QString peerUsername;


};
