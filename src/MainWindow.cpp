#include "BottomWidget.hpp"
#include "CenterWidget.hpp"
#include "TopWidget.hpp"
#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->Top = new TopWidget();
    ui->Bottom = new BottomWidget();
    ui->Center = new CenterWidget();
}

MainWindow::~MainWindow() {
    delete ui;
}
