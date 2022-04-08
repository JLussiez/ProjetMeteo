/********************************************************************************
** Form generated from reading UI file 'TCP_Serveur.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCP_SERVEUR_H
#define UI_TCP_SERVEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TCP_ServeurClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TCP_ServeurClass)
    {
        if (TCP_ServeurClass->objectName().isEmpty())
            TCP_ServeurClass->setObjectName(QString::fromUtf8("TCP_ServeurClass"));
        TCP_ServeurClass->resize(600, 400);
        menuBar = new QMenuBar(TCP_ServeurClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        TCP_ServeurClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TCP_ServeurClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TCP_ServeurClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TCP_ServeurClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        TCP_ServeurClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TCP_ServeurClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TCP_ServeurClass->setStatusBar(statusBar);

        retranslateUi(TCP_ServeurClass);

        QMetaObject::connectSlotsByName(TCP_ServeurClass);
    } // setupUi

    void retranslateUi(QMainWindow *TCP_ServeurClass)
    {
        TCP_ServeurClass->setWindowTitle(QCoreApplication::translate("TCP_ServeurClass", "TCP_Serveur", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TCP_ServeurClass: public Ui_TCP_ServeurClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCP_SERVEUR_H
