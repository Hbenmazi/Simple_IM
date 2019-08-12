#include "ListGUI.h"
#include "List.h"
ListGUI::ListGUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	add = new AddGUI(this);
	add->setModal(true);
	connect(ui.addcontacts_pushButton, SIGNAL(clicked()), this, SLOT(on_AddButton_clicked()));
	connect(List::getInstance(), SIGNAL(ListRefreshed(QJsonObject)),this, SLOT(onListRefreshed(QJsonObject)));
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

void ListGUI::onListRefreshed(QJsonObject user)
{
	QPushButton* button = new QPushButton(this);
	button->setText(user.value("username").toString());
	ui.list_verticalLayout->addWidget(button);
}

void ListGUI::on_AddButton_clicked()
{
	add->show();
}