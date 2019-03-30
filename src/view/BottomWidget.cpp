//
// Created by chevron on 12/03/19.
//

#include <iostream>
#include <include/view/BottomWidget.hpp>
#include <include/model/QPenSingleton.hpp>
#include <QtWidgets/QColorDialog>

BottomWidget::BottomWidget(QWidget *parent) :
        QWidget(parent),
        pen(QPenSingleton::Instance()),
        ui(new Ui::BottomWidget)
{
    ui->setupUi(this);
    dotScene = new QGraphicsScene(this);
    ui->graphicsView->setScene(dotScene);
    dotScene->addEllipse(10,10,10,10, *pen);
}

void BottomWidget::setLineWidth(int lineWidth) {
    BottomWidget::pen->setWidth(lineWidth);
    drawDot();
}

void BottomWidget::chooseColor() {
    QColor choosenColor = QColorDialog::getColor(Qt::black, this);
    if(choosenColor.isValid()){
        setColor(choosenColor);
    }
}

void BottomWidget::chooseBackgroundColor() {
    QColor choosenColor = QColorDialog::getColor(Qt::black, this);
    if(choosenColor.isValid()){
        setBackgroundColor(choosenColor);
    }
}

void BottomWidget::setRainbow(bool rainbow) {
    BottomWidget::ranbow = rainbow;
}

void BottomWidget::setColor(QColor color) {
    BottomWidget::pen->setColor(color);
    drawDot();
}

void BottomWidget::setBackgroundColor(QColor color) {
    emit sendBackgroundColor(&color);
}

void BottomWidget::drawDot() {
    dotScene->clear();
    dotScene->addEllipse(15, 15, pen->width()/2.0, pen->width()/2.0, *pen, pen->brush());
}

Ui::BottomWidget *BottomWidget::getUi() const {
    return ui;
}






