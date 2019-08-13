#include "ChatGUI.h"
#include "qpushbutton.h"
ChatGUI::ChatGUI(QWidget *parent,QString username)
	: QDialog(parent)
{
	ui.setupUi(this);
	setUsername(username);
	chat = new Chat();
	connect(ui.send_pushButton,SIGNAL(clicked()),this,SLOT(onNewMsgSended()));
	connect(this,SIGNAL(NewMsgSended(QString , QString , QString )),chat,SLOT(onNewMsgSended(QString, QString, QString)));
	connect(chat, SIGNAL(LogRefreshed(QVector<QJsonObject>)), this, SLOT(onLogRefreshed(QVector<QJsonObject>)));
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
}

QString ChatGUI::getUsername() const
{
	return username;
}

QString ChatGUI::getPeerUsername() const
{
	return peerUsername;
}

void ChatGUI::onNewMsgSended()
{
	QString username = getUsername();
	QString targetUsername = getPeerUsername();
	QString content = ui.msg_textEdit->toPlainText();

	emit NewMsgSended(username, targetUsername, content);
}

void ChatGUI::myButtonClicked()
{
	QPushButton* button = qobject_cast<QPushButton*>(QObject::sender());

	//���öԵȷ��û���
	setPeerUsername(button->text());
	ui.peerName_label->setText(button->text());

	//ˢ�������¼
	chat->RefreshLog(getUsername(),getPeerUsername());
	this->show();
}


void ChatGUI::onLogRefreshed(QVector<QJsonObject> dataArray)
{
	ui.log_textBrowser->setText("dddd");
}