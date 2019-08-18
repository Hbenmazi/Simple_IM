/********************************************************************************
** Form generated from reading UI file 'Address.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRESS_H
#define UI_ADDRESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Address
{
public:
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *fileport_lineEdit;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *chatport_lineEdit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *ip_lineEdit;
    QPushButton *ok_pushButton;

    void setupUi(QDialog *Address)
    {
        if (Address->objectName().isEmpty())
            Address->setObjectName(QStringLiteral("Address"));
        Address->resize(400, 300);
        horizontalLayoutWidget_3 = new QWidget(Address);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(60, 180, 271, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        fileport_lineEdit = new QLineEdit(horizontalLayoutWidget_3);
        fileport_lineEdit->setObjectName(QStringLiteral("fileport_lineEdit"));

        horizontalLayout_3->addWidget(fileport_lineEdit);

        horizontalLayoutWidget_2 = new QWidget(Address);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(60, 100, 271, 78));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        chatport_lineEdit = new QLineEdit(horizontalLayoutWidget_2);
        chatport_lineEdit->setObjectName(QStringLiteral("chatport_lineEdit"));

        horizontalLayout_2->addWidget(chatport_lineEdit);

        horizontalLayoutWidget = new QWidget(Address);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(60, 20, 271, 78));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        ip_lineEdit = new QLineEdit(horizontalLayoutWidget);
        ip_lineEdit->setObjectName(QStringLiteral("ip_lineEdit"));

        horizontalLayout->addWidget(ip_lineEdit);

        ok_pushButton = new QPushButton(Address);
        ok_pushButton->setObjectName(QStringLiteral("ok_pushButton"));
        ok_pushButton->setGeometry(QRect(260, 270, 75, 23));

        retranslateUi(Address);

        QMetaObject::connectSlotsByName(Address);
    } // setupUi

    void retranslateUi(QDialog *Address)
    {
        Address->setWindowTitle(QApplication::translate("Address", "Address", Q_NULLPTR));
        label_3->setText(QApplication::translate("Address", "File Server Port:", Q_NULLPTR));
        fileport_lineEdit->setText(QApplication::translate("Address", "8002", Q_NULLPTR));
        label_2->setText(QApplication::translate("Address", "Chat Server Port:", Q_NULLPTR));
        chatport_lineEdit->setText(QApplication::translate("Address", "8001", Q_NULLPTR));
        label->setText(QApplication::translate("Address", "IP Address:", Q_NULLPTR));
        ip_lineEdit->setText(QApplication::translate("Address", "127.0.0.1", Q_NULLPTR));
        ok_pushButton->setText(QApplication::translate("Address", "Ok", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Address: public Ui_Address {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRESS_H
