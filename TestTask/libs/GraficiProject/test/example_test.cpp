#include <gtest/gtest.h>

#include <QApplication>

#include "mainwindow.h"



TEST(ExampleTests, Creating) {
    int argc {0};
    QApplication a(argc, nullptr);
    MainWindow w;

    w.show();
    a.exec();
}
