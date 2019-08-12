#include "ListGUI.h"

ListGUI::ListGUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	add = new AddGUI(this);
	add->setModal(true);
	connect(ui.addcontacts_pushButton, SIGNAL(clicked()), this, SLOT(on_AddButton_clicked()));
}

ListGUI::~ListGUI()
{
}

void ListGUI::setUsername(QString username)
{
	this->username = username;
	ui.username_label->setText(username);
}

QString ListGUI::getUsername() const
{
	return username;
}

void ListGUI::on_AddButton_clicked()
{
	add->show();
}