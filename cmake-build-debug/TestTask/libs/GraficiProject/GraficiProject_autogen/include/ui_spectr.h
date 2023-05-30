/********************************************************************************
** Form generated from reading UI file 'spectr.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPECTR_H
#define UI_SPECTR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Spectr
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QCustomPlot *widget_1;
    QCustomPlot *widget_2;

    void setupUi(QDialog *Spectr)
    {
        if (Spectr->objectName().isEmpty())
            Spectr->setObjectName(QString::fromUtf8("Spectr"));
        Spectr->resize(767, 566);
        layoutWidget = new QWidget(Spectr);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 751, 541));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget_1 = new QCustomPlot(layoutWidget);
        widget_1->setObjectName(QString::fromUtf8("widget_1"));

        gridLayout->addWidget(widget_1, 0, 0, 1, 1);

        widget_2 = new QCustomPlot(layoutWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        gridLayout->addWidget(widget_2, 1, 0, 1, 1);


        retranslateUi(Spectr);

        QMetaObject::connectSlotsByName(Spectr);
    } // setupUi

    void retranslateUi(QDialog *Spectr)
    {
        Spectr->setWindowTitle(QCoreApplication::translate("Spectr", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Spectr: public Ui_Spectr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPECTR_H
