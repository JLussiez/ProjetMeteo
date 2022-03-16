/********************************************************************************
** Form generated from reading UI file 'Meteo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_METEO_H
#define UI_METEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MeteoClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MeteoClass)
    {
        if (MeteoClass->objectName().isEmpty())
            MeteoClass->setObjectName(QString::fromUtf8("MeteoClass"));
        MeteoClass->resize(600, 400);
        menuBar = new QMenuBar(MeteoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        MeteoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MeteoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MeteoClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MeteoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MeteoClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MeteoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MeteoClass->setStatusBar(statusBar);

        retranslateUi(MeteoClass);

        QMetaObject::connectSlotsByName(MeteoClass);
    } // setupUi

    void retranslateUi(QMainWindow *MeteoClass)
    {
        MeteoClass->setWindowTitle(QCoreApplication::translate("MeteoClass", "Meteo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MeteoClass: public Ui_MeteoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_METEO_H
