#include "ChatGUI.h"
#include "qpushbutton.h"
ChatGUI::ChatGUI(QWidget *parent,QString username)
	: QDialog(parent)
{
	ui.setupUi(this);
	setUsername(username);
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

void ChatGUI::myButtonClicked()
{
	this->show();
	QPushButton* button = qobject_cast<QPushButton*>(QObject::sender());
	setPeerUsername(button->text());
	ui.peerName_label->setText(button->text());
}
