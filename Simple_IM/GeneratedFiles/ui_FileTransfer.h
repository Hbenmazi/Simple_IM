/********************************************************************************
** Form generated from reading UI file 'FileTransfer.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILETRANSFER_H
#define UI_FILETRANSFER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FileTransfer
{
public:
    QProgressBar *progressBar;
    QLabel *sendStatusLabel;
    QPushButton *open_pushButton;
    QPushButton *send_pushButton;
    QLabel *recvStatusLabel;

    void setupUi(QDialog *FileTransfer)
    {
        if (FileTransfer->objectName().isEmpty())
            FileTransfer->setObjectName(QStringLiteral("FileTransfer"));
        FileTransfer->resize(400, 300);
        progressBar = new QProgressBar(FileTransfer);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(30, 180, 351, 23));
        progressBar->setValue(24);
        sendStatusLabel = new QLabel(FileTransfer);
        sendStatusLabel->setObjectName(QStringLiteral("sendStatusLabel"));
        sendStatusLabel->setGeometry(QRect(10, 20, 381, 31));
        sendStatusLabel->setAlignment(Qt::AlignCenter);
        open_pushButton = new QPushButton(FileTransfer);
        open_pushButton->setObjectName(QStringLiteral("open_pushButton"));
        open_pushButton->setGeometry(QRect(30, 230, 75, 23));
        send_pushButton = new QPushButton(FileTransfer);
        send_pushButton->setObjectName(QStringLiteral("send_pushButton"));
        send_pushButton->setGeometry(QRect(270, 230, 75, 23));
        recvStatusLabel = new QLabel(FileTransfer);
        recvStatusLabel->setObjectName(QStringLiteral("recvStatusLabel"));
        recvStatusLabel->setGeometry(QRect(30, 80, 351, 31));

        retranslateUi(FileTransfer);

        QMetaObject::connectSlotsByName(FileTransfer);
    } // setupUi

    void retranslateUi(QDialog *FileTransfer)
    {
        FileTransfer->setWindowTitle(QApplication::translate("FileTransfer", "FileTransfer", Q_NULLPTR));
        sendStatusLabel->setText(QString());
        open_pushButton->setText(QApplication::translate("FileTransfer", "Open", Q_NULLPTR));
        send_pushButton->setText(QApplication::translate("FileTransfer", "Send", Q_NULLPTR));
        recvStatusLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FileTransfer: public Ui_FileTransfer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILETRANSFER_H
