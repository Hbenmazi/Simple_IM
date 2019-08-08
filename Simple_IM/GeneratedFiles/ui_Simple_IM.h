/********************************************************************************
** Form generated from reading UI file 'Simple_IM.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLE_IM_H
#define UI_SIMPLE_IM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Simple_IMClass
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *RegisterForm;
    QLineEdit *Username_lineEdit;
    QLineEdit *Passward_lineEdit;
    QLineEdit *Passward_2_lineEdit;
    QLineEdit *Nickname_lineEdit;
    QLineEdit *Email_lineEdit;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *LabellLayout;
    QLabel *Username_label;
    QLabel *Passward_label;
    QLabel *Passward_2_label;
    QLabel *Nickname_label;
    QLabel *Email_label;
    QLabel *label;
    QLabel *Tip_label;
    QPushButton *SignUp_pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Simple_IMClass)
    {
        if (Simple_IMClass->objectName().isEmpty())
            Simple_IMClass->setObjectName(QStringLiteral("Simple_IMClass"));
        Simple_IMClass->resize(600, 400);
        centralWidget = new QWidget(Simple_IMClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(130, 10, 311, 321));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(120, 50, 160, 201));
        RegisterForm = new QVBoxLayout(verticalLayoutWidget);
        RegisterForm->setSpacing(6);
        RegisterForm->setContentsMargins(11, 11, 11, 11);
        RegisterForm->setObjectName(QStringLiteral("RegisterForm"));
        RegisterForm->setContentsMargins(0, 0, 0, 0);
        Username_lineEdit = new QLineEdit(verticalLayoutWidget);
        Username_lineEdit->setObjectName(QStringLiteral("Username_lineEdit"));

        RegisterForm->addWidget(Username_lineEdit);

        Passward_lineEdit = new QLineEdit(verticalLayoutWidget);
        Passward_lineEdit->setObjectName(QStringLiteral("Passward_lineEdit"));

        RegisterForm->addWidget(Passward_lineEdit);

        Passward_2_lineEdit = new QLineEdit(verticalLayoutWidget);
        Passward_2_lineEdit->setObjectName(QStringLiteral("Passward_2_lineEdit"));

        RegisterForm->addWidget(Passward_2_lineEdit);

        Nickname_lineEdit = new QLineEdit(verticalLayoutWidget);
        Nickname_lineEdit->setObjectName(QStringLiteral("Nickname_lineEdit"));

        RegisterForm->addWidget(Nickname_lineEdit);

        Email_lineEdit = new QLineEdit(verticalLayoutWidget);
        Email_lineEdit->setObjectName(QStringLiteral("Email_lineEdit"));

        RegisterForm->addWidget(Email_lineEdit);

        verticalLayoutWidget_2 = new QWidget(frame);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 50, 104, 191));
        LabellLayout = new QVBoxLayout(verticalLayoutWidget_2);
        LabellLayout->setSpacing(6);
        LabellLayout->setContentsMargins(11, 11, 11, 11);
        LabellLayout->setObjectName(QStringLiteral("LabellLayout"));
        LabellLayout->setContentsMargins(0, 0, 0, 0);
        Username_label = new QLabel(verticalLayoutWidget_2);
        Username_label->setObjectName(QStringLiteral("Username_label"));
        Username_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        LabellLayout->addWidget(Username_label);

        Passward_label = new QLabel(verticalLayoutWidget_2);
        Passward_label->setObjectName(QStringLiteral("Passward_label"));
        Passward_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        LabellLayout->addWidget(Passward_label);

        Passward_2_label = new QLabel(verticalLayoutWidget_2);
        Passward_2_label->setObjectName(QStringLiteral("Passward_2_label"));
        Passward_2_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        LabellLayout->addWidget(Passward_2_label);

        Nickname_label = new QLabel(verticalLayoutWidget_2);
        Nickname_label->setObjectName(QStringLiteral("Nickname_label"));
        Nickname_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        LabellLayout->addWidget(Nickname_label);

        Email_label = new QLabel(verticalLayoutWidget_2);
        Email_label->setObjectName(QStringLiteral("Email_label"));
        Email_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        LabellLayout->addWidget(Email_label);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 10, 71, 21));
        label->setAlignment(Qt::AlignCenter);
        Tip_label = new QLabel(frame);
        Tip_label->setObjectName(QStringLiteral("Tip_label"));
        Tip_label->setGeometry(QRect(60, 260, 201, 16));
        Tip_label->setAlignment(Qt::AlignCenter);
        SignUp_pushButton = new QPushButton(frame);
        SignUp_pushButton->setObjectName(QStringLiteral("SignUp_pushButton"));
        SignUp_pushButton->setGeometry(QRect(110, 290, 75, 23));
        Simple_IMClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Simple_IMClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        Simple_IMClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Simple_IMClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Simple_IMClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Simple_IMClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Simple_IMClass->setStatusBar(statusBar);

        retranslateUi(Simple_IMClass);

        QMetaObject::connectSlotsByName(Simple_IMClass);
    } // setupUi

    void retranslateUi(QMainWindow *Simple_IMClass)
    {
        Simple_IMClass->setWindowTitle(QApplication::translate("Simple_IMClass", "Simple_IM", Q_NULLPTR));
        Username_label->setText(QApplication::translate("Simple_IMClass", "Username:", Q_NULLPTR));
        Passward_label->setText(QApplication::translate("Simple_IMClass", "Passward:", Q_NULLPTR));
        Passward_2_label->setText(QApplication::translate("Simple_IMClass", "Confirm Passward:", Q_NULLPTR));
        Nickname_label->setText(QApplication::translate("Simple_IMClass", "Nickname:", Q_NULLPTR));
        Email_label->setText(QApplication::translate("Simple_IMClass", "Email:", Q_NULLPTR));
        label->setText(QApplication::translate("Simple_IMClass", "Sign Up", Q_NULLPTR));
        Tip_label->setText(QString());
        SignUp_pushButton->setText(QApplication::translate("Simple_IMClass", "Sign Up", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Simple_IMClass: public Ui_Simple_IMClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLE_IM_H
