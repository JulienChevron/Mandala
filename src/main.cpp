//
// Created by chopinet on 26/02/19.
//
#include "include/MainWindow.hpp"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

