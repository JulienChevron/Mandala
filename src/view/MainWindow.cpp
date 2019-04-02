
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
    connect(ui->actionOpen_2, SIGNAL(triggered()), ui->center->getUi()->drawingArea, SLOT(openNewImage()));
    connect(ui->actionUndo, SIGNAL(triggered()), ui->center->getUi()->drawingArea, SLOT(undo()));
    connect(ui->actionRedo, SIGNAL(triggered()), ui->center->getUi()->drawingArea, SLOT(redo()));
    connect(ui->actionSave_as, SIGNAL(triggered()), ui->center->getUi()->drawingArea, SLOT(saveCurrentImage()));
    connect(ui->top->getUi()->clearButton, SIGNAL(pressed()),  ui->center->getUi()->drawingArea, SLOT(clearImage()));
    connect(ui->top->getUi()->grid_slider, SIGNAL(valueChanged(int)),  ui->center->getUi()->drawingArea, SLOT(setGridOpacity(int)));
    connect(ui->top->getUi()->grid_btn, SIGNAL(clicked(bool)),  ui->center->getUi()->drawingArea, SLOT(setGrid(bool)));
    connect(ui->top->getUi()->mirror_btn, SIGNAL(clicked(bool)),  ui->center->getUi()->drawingArea, SLOT(setMirror(bool)));
    connect(ui->top->getUi()->spinBox, SIGNAL(valueChanged(int)),  ui->center->getUi()->drawingArea, SLOT(setGridSlice(int)));
    connect(ui->bottom->getUi()->rainbow_btn, SIGNAL(clicked(bool)),  ui->center->getUi()->drawingArea, SLOT(setRainbow(bool)));
    connect(ui->bottom->getUi()->erase_btn, SIGNAL(clicked(bool)),  ui->center->getUi()->drawingArea, SLOT(setErase(bool)));
    connect(ui->bottom->getUi()->line_btn, SIGNAL(clicked(bool)),  ui->center->getUi()->drawingArea, SLOT(setLineMode(bool)));
    connect(ui->top, SIGNAL(sendSize(QSize*)), ui->center->getUi()->drawingArea, SLOT(setSize(QSize*)));
    connect(ui->bottom, SIGNAL(sendBackgroundColor(QColor*)), ui->center->getUi()->drawingArea, SLOT(setBackgroundColor(QColor*)));
    connect(ui->bottom, SIGNAL(changeLineWidth(int)), ui->center->getUi()->drawingArea, SLOT(setLineWidth(int)));
    ui->center->getUi()->drawingArea->setSize(new QSize(800,800));
    this->setWindowTitle("Nelson Mandala");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::displayHelp() {
    QMessageBox about;
    about.setWindowTitle("About Neslon Mandala");
    about.setText("Nelson Mandala : The Mandala revolution\n"
                  "Created by Pierre Chopinet & Julien Chevron");
    about.setInformativeText("(C) 2019 CCC-Development-Team");
    about.setStandardButtons(QMessageBox::Ok);
    QPixmap mandala("../img/ensi.png");
    about.setIconPixmap(mandala);
    about.setDefaultButton(QMessageBox::Ok);
    about.show();
    about.exec();
}

void MainWindow::exit() {
    QApplication::quit();
}
