/********************************************************************************
** Form generated from reading UI file 'ListGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTGUI_H
#define UI_LISTGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListGUI
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *username_label;
    QFrame *list_frame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *list_verticalLayout;
    QPushButton *addcontacts_pushButton;

    void setupUi(QDialog *ListGUI)
    {
        if (ListGUI->objectName().isEmpty())
            ListGUI->setObjectName(QStringLiteral("ListGUI"));
        ListGUI->resize(239, 519);
        formLayoutWidget = new QWidget(ListGUI);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 10, 171, 16));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        username_label = new QLabel(formLayoutWidget);
        username_label->setObjectName(QStringLiteral("username_label"));

        formLayout->setWidget(0, QFormLayout::FieldRole, username_label);

        list_frame = new QFrame(ListGUI);
        list_frame->setObjectName(QStringLiteral("list_frame"));
        list_frame->setGeometry(QRect(10, 40, 221, 431));
        list_frame->setAutoFillBackground(false);
        list_frame->setFrameShape(QFrame::Box);
        list_frame->setFrameShadow(QFrame::Raised);
        list_frame->setLineWidth(1);
        verticalLayoutWidget = new QWidget(list_frame);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 221, 431));
        list_verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        list_verticalLayout->setSpacing(6);
        list_verticalLayout->setContentsMargins(11, 11, 11, 11);
        list_verticalLayout->setObjectName(QStringLiteral("list_verticalLayout"));
        list_verticalLayout->setContentsMargins(0, 0, 0, 0);
        addcontacts_pushButton = new QPushButton(ListGUI);
        addcontacts_pushButton->setObjectName(QStringLiteral("addcontacts_pushButton"));
        addcontacts_pushButton->setGeometry(QRect(134, 480, 101, 23));

        retranslateUi(ListGUI);

        QMetaObject::connectSlotsByName(ListGUI);
    } // setupUi

    void retranslateUi(QDialog *ListGUI)
    {
        ListGUI->setWindowTitle(QApplication::translate("ListGUI", "ListGUI", Q_NULLPTR));
        label->setText(QApplication::translate("ListGUI", "username:", Q_NULLPTR));
        username_label->setText(QString());
        addcontacts_pushButton->setText(QApplication::translate("ListGUI", "Add Contacts", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ListGUI: public Ui_ListGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTGUI_H
