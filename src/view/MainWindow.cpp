
#include "include/view/MainWindow.hpp"
#include <QtWidgets/QMessageBox>
#include "include/view/BottomWidget.hpp"
#include "include/view/CenterWidget.hpp"
#include "include/view/TopWidget.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->actionUndo, SIGNAL(triggered()), ui->center, SLOT(undo()));
    connect(ui->actionRedo, SIGNAL(triggered()), ui->center, SLOT(redo()));
    connect(ui->actionSave_as, SIGNAL(triggered()), ui->center, SLOT(saveCurrentImage()));
    connect(ui->top->getUi()->clearButton, SIGNAL(pressed()), ui->center, SLOT(clearImage()));
    connect(ui->top->getUi()->grid_slider, SIGNAL(valueChanged(int)), ui->center, SLOT(setGridOpacity(int)));
    connect(ui->top->getUi()->grid, SIGNAL(clicked(bool)), ui->center, SLOT(setGrid(bool)));
    connect(ui->top->getUi()->mirror, SIGNAL(clicked(bool)), ui->center, SLOT(setMirror(bool)));
    connect(ui->top->getUi()->spinBox, SIGNAL(valueChanged(int)), ui->center, SLOT(setGridSlice(int)));
    connect(ui->top, SIGNAL(sendSize(QSize*)), ui->center, SLOT(setSize(QSize*)));
    ui->center->setSize(new QSize(800,600));

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::displayHelp() {
    QMessageBox::information(
            this,
            tr("About NeslonMandala"),
            tr("NelsonMandala : The best Mandala open source project\n"
               "(C) 2019 CCC Development Team"));
}

void MainWindow::exit() {
    QApplication::quit();
}
