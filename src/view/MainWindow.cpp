
#include "include/view/MainWindow.hpp"
#include <QMessageBox>
#include "include/view/BottomWidget.hpp"
#include "include/view/CenterWidget.hpp"
#include "include/view/TopWidget.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->actionUndo, SIGNAL(triggered()), ui->center->getUi()->drawingArea, SLOT(undo()));
    connect(ui->actionRedo, SIGNAL(triggered()), ui->center->getUi()->drawingArea, SLOT(redo()));
    connect(ui->actionSave_as, SIGNAL(triggered()), ui->center->getUi()->drawingArea, SLOT(saveCurrentImage()));
    connect(ui->top->getUi()->clearButton, SIGNAL(pressed()),  ui->center->getUi()->drawingArea, SLOT(clearImage()));
    connect(ui->top->getUi()->grid_slider, SIGNAL(valueChanged(int)),  ui->center->getUi()->drawingArea, SLOT(setGridOpacity(int)));
    connect(ui->top->getUi()->grid, SIGNAL(clicked(bool)),  ui->center->getUi()->drawingArea, SLOT(setGrid(bool)));
    connect(ui->top->getUi()->mirror, SIGNAL(clicked(bool)),  ui->center->getUi()->drawingArea, SLOT(setMirror(bool)));
    connect(ui->top->getUi()->spinBox, SIGNAL(valueChanged(int)),  ui->center->getUi()->drawingArea, SLOT(setGridSlice(int)));
    connect(ui->bottom->getUi()->rainbow_btn, SIGNAL(clicked(bool)),  ui->center->getUi()->drawingArea, SLOT(setRainbow(bool)));
    connect(ui->top, SIGNAL(sendSize(QSize*)), ui->center->getUi()->drawingArea, SLOT(setSize(QSize*)));
    connect(ui->bottom, SIGNAL(sendBackgroundColor(QColor*)), ui->center->getUi()->drawingArea, SLOT(setBackgroundColor(QColor*)));
    ui->center->getUi()->drawingArea->setSize(new QSize(800,800));
    this->setWindowTitle("Nelson Mandala");

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
