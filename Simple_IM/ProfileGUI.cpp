#include "ProfileGUI.h"

ProfileGUI::ProfileGUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.select_pushButton, SIGNAL(clicked()), this, SLOT(onSelectButtonClicked()));
}

ProfileGUI::~ProfileGUI()
{
}

void ProfileGUI::onSelectButtonClicked()
{
	if (ui.radioButton_1->isChecked())
		emit SelectButtonClicked(ui.radioButton_1->objectName());
	if (ui.radioButton_2->isChecked())
		emit SelectButtonClicked(ui.radioButton_2->objectName());
	if (ui.radioButton_3->isChecked())
		emit SelectButtonClicked(ui.radioButton_3->objectName());
	if (ui.radioButton_4->isChecked())
		emit SelectButtonClicked(ui.radioButton_4->objectName());
	if (ui.radioButton_5->isChecked())
		emit SelectButtonClicked(ui.radioButton_5->objectName());
	if (ui.radioButton_6->isChecked())
		emit SelectButtonClicked(ui.radioButton_6->objectName());
	if (ui.radioButton_7->isChecked())
		emit SelectButtonClicked(ui.radioButton_7->objectName());
	if (ui.radioButton_8->isChecked())
		emit SelectButtonClicked(ui.radioButton_8->objectName());
	if (ui.radioButton_9->isChecked())
		emit SelectButtonClicked(ui.radioButton_9->objectName());

	close();
}

