
#include "include/MainWindow.hpp"
#include <QtWidgets/QMessageBox>
#include "include/BottomWidget.hpp"
#include "include/CenterWidget.hpp"
#include "include/TopWidget.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::displayHelp() {
    QMessageBox::information(
                this,
                tr("About NeslonMandala"),
                tr("NelsonMandala : The best Mandala open source project\n"
                   "(C) 2019 CCC Development Team") );
}

void MainWindow::exit(){
    QApplication::quit();
}
