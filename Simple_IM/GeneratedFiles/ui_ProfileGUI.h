/********************************************************************************
** Form generated from reading UI file 'ProfileGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEGUI_H
#define UI_PROFILEGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_ProfileGUI
{
public:
    QGroupBox *groupBox;
    QPushButton *select_pushButton;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_9;
    QRadioButton *radioButton_8;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_6;

    void setupUi(QDialog *ProfileGUI)
    {
        if (ProfileGUI->objectName().isEmpty())
            ProfileGUI->setObjectName(QStringLiteral("ProfileGUI"));
        ProfileGUI->resize(502, 485);
        groupBox = new QGroupBox(ProfileGUI);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 20, 451, 431));
        select_pushButton = new QPushButton(groupBox);
        select_pushButton->setObjectName(QStringLiteral("select_pushButton"));
        select_pushButton->setGeometry(QRect(340, 380, 75, 23));
        radioButton_1 = new QRadioButton(groupBox);
        radioButton_1->setObjectName(QStringLiteral("radioButton_1"));
        radioButton_1->setGeometry(QRect(20, 20, 111, 111));
        radioButton_1->setStyleSheet(QStringLiteral("image: url(:/Simple_IM/Resources/head1.jpg);"));
        radioButton_5 = new QRadioButton(groupBox);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(160, 140, 111, 111));
        radioButton_5->setStyleSheet(QStringLiteral("image: url(:/Simple_IM/Resources/head5.jpg);"));
        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(20, 140, 111, 111));
        radioButton_4->setStyleSheet(QStringLiteral("image: url(:/Simple_IM/Resources/head4.jpg);"));
        radioButton_9 = new QRadioButton(groupBox);
        radioButton_9->setObjectName(QStringLiteral("radioButton_9"));
        radioButton_9->setGeometry(QRect(300, 260, 111, 111));
        radioButton_9->setStyleSheet(QStringLiteral("image: url(:/Simple_IM/Resources/head9.jpg);"));
        radioButton_8 = new QRadioButton(groupBox);
        radioButton_8->setObjectName(QStringLiteral("radioButton_8"));
        radioButton_8->setGeometry(QRect(160, 260, 111, 111));
        radioButton_8->setStyleSheet(QStringLiteral("image: url(:/Simple_IM/Resources/head8.jpg);"));
        radioButton_7 = new QRadioButton(groupBox);
        radioButton_7->setObjectName(QStringLiteral("radioButton_7"));
        radioButton_7->setGeometry(QRect(20, 260, 111, 111));
        radioButton_7->setStyleSheet(QStringLiteral("image: url(:/Simple_IM/Resources/head7.jpg);"));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(160, 20, 111, 111));
        radioButton_2->setStyleSheet(QStringLiteral("image: url(:/Simple_IM/Resources/head2.jpg);"));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(300, 20, 111, 111));
        radioButton_3->setStyleSheet(QStringLiteral("image: url(:/Simple_IM/Resources/head3.jpg);"));
        radioButton_6 = new QRadioButton(groupBox);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        radioButton_6->setGeometry(QRect(300, 140, 111, 111));
        radioButton_6->setStyleSheet(QStringLiteral("image: url(:/Simple_IM/Resources/head6.jpg);"));

        retranslateUi(ProfileGUI);

        QMetaObject::connectSlotsByName(ProfileGUI);
    } // setupUi

    void retranslateUi(QDialog *ProfileGUI)
    {
        ProfileGUI->setWindowTitle(QApplication::translate("ProfileGUI", "ProfileGUI", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ProfileGUI", "GroupBox", Q_NULLPTR));
        select_pushButton->setText(QApplication::translate("ProfileGUI", "select", Q_NULLPTR));
        radioButton_1->setText(QString());
        radioButton_5->setText(QString());
        radioButton_4->setText(QString());
        radioButton_9->setText(QString());
        radioButton_8->setText(QString());
        radioButton_7->setText(QString());
        radioButton_2->setText(QString());
        radioButton_3->setText(QString());
        radioButton_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ProfileGUI: public Ui_ProfileGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEGUI_H
