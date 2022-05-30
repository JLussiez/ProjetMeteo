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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MeteoClass
{
public:
    QWidget *centralWidget;
    QPushButton *BouttonTest;
    QLabel *label;
    QLabel *label_2;
    QLabel *Tension;
    QLabel *Pression;
    QLabel *label_3;
    QLabel *prevision;
    QLabel *label_4;
    QLabel *prevision_2;
    QLabel *label_5;
    QLabel *prevision_3;
    QLabel *prevision_4;
    QLabel *prevision_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MeteoClass)
    {
        if (MeteoClass->objectName().isEmpty())
            MeteoClass->setObjectName(QString::fromUtf8("MeteoClass"));
        MeteoClass->resize(684, 470);
        centralWidget = new QWidget(MeteoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        BouttonTest = new QPushButton(centralWidget);
        BouttonTest->setObjectName(QString::fromUtf8("BouttonTest"));
        BouttonTest->setGeometry(QRect(270, 180, 151, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 90, 101, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(430, 90, 101, 21));
        Tension = new QLabel(centralWidget);
        Tension->setObjectName(QString::fromUtf8("Tension"));
        Tension->setGeometry(QRect(150, 130, 101, 21));
        Pression = new QLabel(centralWidget);
        Pression->setObjectName(QString::fromUtf8("Pression"));
        Pression->setGeometry(QRect(430, 130, 101, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(320, 230, 51, 21));
        prevision = new QLabel(centralWidget);
        prevision->setObjectName(QString::fromUtf8("prevision"));
        prevision->setGeometry(QRect(290, 270, 101, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(450, 230, 91, 21));
        prevision_2 = new QLabel(centralWidget);
        prevision_2->setObjectName(QString::fromUtf8("prevision_2"));
        prevision_2->setGeometry(QRect(440, 280, 101, 21));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(120, 230, 121, 21));
        prevision_3 = new QLabel(centralWidget);
        prevision_3->setObjectName(QString::fromUtf8("prevision_3"));
        prevision_3->setGeometry(QRect(120, 270, 101, 21));
        prevision_4 = new QLabel(centralWidget);
        prevision_4->setObjectName(QString::fromUtf8("prevision_4"));
        prevision_4->setGeometry(QRect(300, 310, 101, 21));
        prevision_5 = new QLabel(centralWidget);
        prevision_5->setObjectName(QString::fromUtf8("prevision_5"));
        prevision_5->setGeometry(QRect(290, 350, 101, 21));
        MeteoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MeteoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 684, 21));
        MeteoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MeteoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MeteoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MeteoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MeteoClass->setStatusBar(statusBar);

        retranslateUi(MeteoClass);
        QObject::connect(BouttonTest, SIGNAL(clicked()), MeteoClass, SLOT(TestTension()));

        QMetaObject::connectSlotsByName(MeteoClass);
    } // setupUi

    void retranslateUi(QMainWindow *MeteoClass)
    {
        MeteoClass->setWindowTitle(QCoreApplication::translate("MeteoClass", "Meteo", nullptr));
        BouttonTest->setText(QCoreApplication::translate("MeteoClass", "Obtenir une tension al\303\251atoire", nullptr));
        label->setText(QCoreApplication::translate("MeteoClass", "Tension G\303\251n\303\251rer : ", nullptr));
        label_2->setText(QCoreApplication::translate("MeteoClass", "Pression obtenue : ", nullptr));
        Tension->setText(QString());
        Pression->setText(QString());
        label_3->setText(QCoreApplication::translate("MeteoClass", "Pr\303\251vision", nullptr));
        prevision->setText(QString());
        label_4->setText(QCoreApplication::translate("MeteoClass", "Derni\303\250re Pression", nullptr));
        prevision_2->setText(QString());
        label_5->setText(QCoreApplication::translate("MeteoClass", "6e Pression Precedante", nullptr));
        prevision_3->setText(QString());
        prevision_4->setText(QCoreApplication::translate("MeteoClass", "Diff\303\251rence Pression", nullptr));
        prevision_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MeteoClass: public Ui_MeteoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_METEO_H
