
#include "MainWindow.h"
#include <QtWidgets/QMessageBox>
#include "BottomWidget.hpp"
#include "CenterWidget.hpp"
#include "TopWidget.hpp"
#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
    top = new TopWidget(this);
    center = new CenterWidget(this);
    bottom = new BottomWidget(this);
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
