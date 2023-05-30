/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QPushButton *start;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QRadioButton *sig_triug;
    QRadioButton *sig_garm;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *lineEdit_7;
    QLabel *label_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_6;
    QRadioButton *sig_lchm;
    QLabel *label_8;
    QLineEdit *lineEdit_1;
    QLabel *label_6;
    QLineEdit *lineEdit_5;
    QLabel *label_7;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QCustomPlot *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(766, 507);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        start = new QPushButton(groupBox);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(220, 400, 351, 41));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 270, 701, 120));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 2, 1, 1);

        sig_triug = new QRadioButton(layoutWidget);
        sig_triug->setObjectName(QString::fromUtf8("sig_triug"));

        gridLayout->addWidget(sig_triug, 2, 0, 1, 2);

        sig_garm = new QRadioButton(layoutWidget);
        sig_garm->setObjectName(QString::fromUtf8("sig_garm"));

        gridLayout->addWidget(sig_garm, 0, 0, 1, 2);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 5, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        lineEdit_7 = new QLineEdit(layoutWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(lineEdit_7, 2, 3, 1, 2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(lineEdit_4, 1, 3, 1, 2);

        lineEdit_6 = new QLineEdit(layoutWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(lineEdit_6, 1, 10, 1, 1);

        sig_lchm = new QRadioButton(layoutWidget);
        sig_lchm->setObjectName(QString::fromUtf8("sig_lchm"));

        gridLayout->addWidget(sig_lchm, 1, 0, 1, 2);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 1, 8, 1, 1);

        lineEdit_1 = new QLineEdit(layoutWidget);
        lineEdit_1->setObjectName(QString::fromUtf8("lineEdit_1"));
        lineEdit_1->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(lineEdit_1, 0, 3, 1, 2);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 8, 1, 1);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(lineEdit_5, 1, 6, 1, 2);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 1, 5, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(lineEdit_2, 0, 6, 1, 2);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(lineEdit_3, 0, 10, 1, 1);

        widget = new QCustomPlot(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 10, 701, 261));

        verticalLayout_3->addWidget(groupBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 766, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        start->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \321\201\320\270\320\263\320\275\320\260\320\273", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "t(0;1)", nullptr));
        sig_triug->setText(QCoreApplication::translate("MainWindow", "\320\242\321\200\320\270\321\203\320\263\320\276\320\273\321\214\320\275\321\213\320\271 \320\270\320\274\320\277\321\203\320\273\321\214\321\201", nullptr));
        sig_garm->setText(QCoreApplication::translate("MainWindow", "\320\223\320\260\321\200\320\274\320\276\320\275\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \321\201\320\270\320\263\320\275\320\260\320\273", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "       phi", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "       f0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "       f0", nullptr));
        sig_lchm->setText(QCoreApplication::translate("MainWindow", "\320\233\320\247\320\234", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "        Fd", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "        Fd", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", " delta f", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
