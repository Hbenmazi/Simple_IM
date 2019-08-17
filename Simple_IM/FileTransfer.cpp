#include "FileTransfer.h"
#include <QHostAddress>
#include <QTextCodec>
#include <QFileDialog>
#include"Client.h"
#include"qjsondocument.h"
FileTransfer::FileTransfer(QString peerUsername,QWidget *parent)
	: QDialog(parent)
{
	this->peerUsername = peerUsername;
	ui.setupUi(this);

	ui.progressBar->hide();

	sendTimes = 0;
	totalSize_in = 0;
	byteReceived = 0;
	connect(ui.open_pushButton, SIGNAL(clicked()), this, SLOT(onOpenPushButtonClicked()));
	connect(ui.send_pushButton, SIGNAL(clicked()), this, SLOT(onSendPushButtonClicked()));
	connect(Client::getInstance(), SIGNAL(FileSocketReadyRead(QByteArray)), this, SLOT(onFileSocketReadyRead(QByteArray)));
}

FileTransfer::~FileTransfer()
{
}

void FileTransfer::setPeerUsername(QString peerUsername)
{
	this->peerUsername = peerUsername;
}

void FileTransfer::SendHeader()  //�����ļ�ͷ��Ϣ
{
	connect(Client::getInstance()->getFileSocket(), SIGNAL(bytesWritten(qint64)), this, SLOT(goOnSend(qint64)));

	byteToWrite = localFile->size();  //ʣ�����ݵĴ�С
	totalSize_out = localFile->size();

	loadSize = 4 * 1024;  //ÿ�η������ݵĴ�С

	QDataStream out(&outBlock, QIODevice::WriteOnly);
	QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/') - 1);
	QString isHeader("header");
	out << qint64(0) << qint64(0)<<isHeader<<peerUsername<< currentFileName;

	totalSize_out += outBlock.size();  //�ܴ�СΪ�ļ���С�����ļ�������Ϣ��С
	byteToWrite += outBlock.size();

	out.device()->seek(0);  //�ص��ֽ��������д��ǰ������qint64���ֱ�Ϊ�ܴ�С���ļ�������Ϣ��С
	out << totalSize_out << qint64(outBlock.size());
	qDebug() << outBlock;
	Client::getInstance()->getFileSocket()->write(outBlock);  //���������ļ����͵��׽���

	ui.progressBar->show();
	ui.progressBar->setMaximum(totalSize_out);
	ui.progressBar->setValue(totalSize_out - byteToWrite);
}

void FileTransfer::goOnSend(qint64 numBytes)  //��ʼ�����ļ�����
{
	byteToWrite -= numBytes;  //ʣ�����ݴ�С
	outBlock = localFile->read(qMin(byteToWrite, loadSize));
	Client::getInstance()->getFileSocket()->write(outBlock);  //���������ļ����͵��׽���

	ui.progressBar->setMaximum(totalSize_out);
	ui.progressBar->setValue(totalSize_out - byteToWrite);

	if (byteToWrite == 0)  //�������
		ui.sendStatusLabel->setText("Finished");
}

void FileTransfer::onOpenPushButtonClicked()  //���ļ�����ȡ�ļ���������·����
{
	ui.sendStatusLabel->setText("Opening...");
	ui.progressBar->setValue(0);  //�ǵ�һ�η���

	loadSize = 0;
	byteToWrite = 0;
	totalSize_out = 0;
	outBlock.clear();

	fileName = QFileDialog::getOpenFileName(this);
	localFile = new QFile(fileName);
	localFile->open(QFile::ReadOnly);

	ui.sendStatusLabel->setText(QString("filename: %1").arg(fileName));
}

void FileTransfer::onSendPushButtonClicked()
{
	
    SendHeader();  

	ui.sendStatusLabel->setText(QString("transfering %1").arg(fileName));
}

void FileTransfer::onFileSocketReadyRead(QByteArray data)
{
	if (byteReceived == 0)  //�Ÿտ�ʼ�������ݣ�������Ϊ�ļ���Ϣ
	{
		QDir *folder = new QDir;
		//�жϴ����ļ����Ƿ����
		bool exist = folder->exists("D:/File");

		if (!exist)//�����ļ���
			bool ok = folder->mkdir("D:/File");
		
	
		QString temp;
		QDataStream in(data);
		in >> totalSize_in >> byteReceived >>temp>>peerUsername>> fileName_in;
		fileName_in = "D:/File/" + fileName_in;
		newFile = new QFile(fileName_in);
		bool isopen = newFile->open(QFile::WriteOnly);
		qDebug() << "isopen" << isopen;

		QString status = "Your friend is sending a file to you:" + fileName_in;
		ui.open_pushButton->hide();
		ui.send_pushButton->hide();
		ui.recvStatusLabel->setText(status);
		show();
		ui.progressBar->show();
		ui.progressBar->setMaximum(totalSize_in);
		ui.progressBar->setValue(byteReceived);

	}
	else  //��ʽ��ȡ�ļ�����
	{
		inBlock = data;
		byteReceived += inBlock.size();
		qDebug()<<"write"<<newFile->write(inBlock);
		qDebug()<<"flush"<<newFile->flush();

		ui.progressBar->setMaximum(totalSize_in);
		ui.progressBar->setValue(byteReceived);
	}

}
