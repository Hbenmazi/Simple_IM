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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Simple_IMClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Simple_IMClass)
    {
        if (Simple_IMClass->objectName().isEmpty())
            Simple_IMClass->setObjectName(QStringLiteral("Simple_IMClass"));
        Simple_IMClass->resize(600, 400);
        menuBar = new QMenuBar(Simple_IMClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Simple_IMClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Simple_IMClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Simple_IMClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Simple_IMClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Simple_IMClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Simple_IMClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Simple_IMClass->setStatusBar(statusBar);

        retranslateUi(Simple_IMClass);

        QMetaObject::connectSlotsByName(Simple_IMClass);
    } // setupUi

    void retranslateUi(QMainWindow *Simple_IMClass)
    {
        Simple_IMClass->setWindowTitle(QApplication::translate("Simple_IMClass", "Simple_IM", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Simple_IMClass: public Ui_Simple_IMClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLE_IM_H
