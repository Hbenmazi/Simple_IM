#include "ListGUI.h"
#include "List.h"
#include "qvector.h"
ListGUI::ListGUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	add = new AddGUI(this);
	add->setModal(true);
	connect(ui.addcontacts_pushButton, SIGNAL(clicked()), this, SLOT(on_AddButton_clicked()));
	connect(List::getInstance(), SIGNAL(ListRefreshed(QVector<QJsonObject>)),this, SLOT(onListRefreshed(QVector<QJsonObject>)));
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

void ListGUI::onListRefreshed(QVector<QJsonObject> userArray)
{
	int friendlist_size = friendlist.size();
	for (int i = 0;i< friendlist_size;i++)
	{
		QPushButton* temp = friendlist.at(0);
		ui.list_verticalLayout->removeWidget(temp);
		friendlist.remove(0);
		temp->~QPushButton();
	}

	for (QJsonObject user : userArray)
	{
		QPushButton* button = new QPushButton(this);
		button->setText(user.value("username").toString());
		friendlist.append(button);
		ui.list_verticalLayout->addWidget(button);
	}
	
}

void ListGUI::on_AddButton_clicked()
{
	add->show();
}