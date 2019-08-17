#include "ChatGUI.h"
#include "qpushbutton.h"
#include "qlistwidget.h"
#include"Client.h"
ChatGUI::ChatGUI(QWidget *parent, QString username)
	: QDialog(parent)
{
	ui.setupUi(this);
	setUsername(username);
	chat = new Chat();
	fileTransfer = new FileTransfer();
	connect(ui.send_pushButton, SIGNAL(clicked()), this, SLOT(onNewMsgSended()));
	connect(ui.transerFile_pushButton, SIGNAL(clicked()), this, SLOT(onTransferFileButtonClicked()));
	connect(this, SIGNAL(NewMsgSended(QString, QString, QString)), chat, SLOT(onNewMsgSended(QString, QString, QString)));
	connect(chat, SIGNAL(LogRefreshed(QVector<QJsonObject>)), this, SLOT(onLogRefreshed(QVector<QJsonObject>)));
	ui.msg_textEdit.set
}

ChatGUI::~ChatGUI()
{
}

void ChatGUI::setUsername(QString username)
{
	this->username = username;
}

void ChatGUI::setPeerUsername(QString peerUsername)
{
	this->peerUsername = peerUsername;
	fileTransfer->setPeerUsername(peerUsername);
	
}

QString ChatGUI::getUsername() const
{
	return username;
}

QString ChatGUI::getPeerUsername() const
{
	return peerUsername;
}

void ChatGUI::closeEvent(QCloseEvent * event)
{
	myButton->setText(getPeerUsername() + "(0)");
}

void ChatGUI::onNewMsgSended()
{
	QString username = getUsername();
	QString targetUsername = getPeerUsername();
	QString content = ui.msg_textEdit->toPlainText();

	emit NewMsgSended(username, targetUsername, content);
	ui.msg_textEdit->clear();
}

void ChatGUI::myButtonClicked()
{
	myButton = qobject_cast<QPushButton*>(QObject::sender());
	//���öԵȷ��û���
	setPeerUsername(myButton->text().section(QRegExp("[()]"), 0, 0).trimmed());
	ui.peerName_label->setText(myButton->text());

	//ˢ�������¼
	ui.log_listWidget->clear();
	chat->RefreshLog(getUsername(),getPeerUsername());

	this->show();
}


void ChatGUI::onLogRefreshed(QVector<QJsonObject> dataArray)
{
	emit LogRefreshed(dataArray);
	for (QJsonObject data : dataArray)
	{
		QString sender_name = data.value("sender_name").toString();
		if(sender_name == peerUsername || sender_name == username)
			displayLog(data);
	}

}

void ChatGUI::displayLog(QJsonObject data)
{
	QString sender_name = data.value("sender_name").toString();
	QString time = data.value("time").toString();
	QString title = sender_name + "   " + time;
	QString content = data.value("content").toString();

	QListWidgetItem *title_item = new QListWidgetItem;
	title_item->setText(title);

	QListWidgetItem *content_item = new QListWidgetItem;
	content_item->setText(content);

	QListWidgetItem *empty_item = new QListWidgetItem;

	ui.log_listWidget->addItem(title_item);
	ui.log_listWidget->addItem(content_item);
	ui.log_listWidget->addItem(empty_item);

	ui.log_listWidget->scrollToBottom();
}

void ChatGUI::onTransferFileButtonClicked()
{
	chat->onTransferFileButtonClicked(getUsername());
	fileTransfer->show();
}
