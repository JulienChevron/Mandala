//
// Created by chevron on 12/03/19.
//

#include <iostream>
#include <QtWidgets/QColorDialog>
#include <include/view/BottomWidget.hpp>
#include <include/model/QPenSingleton.hpp>

#include "include/view/BottomWidget.hpp"

BottomWidget::BottomWidget(QWidget *parent) :
        QWidget(parent),
        pen(QPenSingleton::Instance()),
        ui(new Ui::BottomWidget)
{
    ui->setupUi(this);
}

void BottomWidget::setLineWidth(int lineWidth) {
    BottomWidget::pen->setWidth(lineWidth);
}

void BottomWidget::chooseColor() {
    QColor choosenColor = QColorDialog::getColor(Qt::black, this);
    if(choosenColor.isValid()){
        setColor(choosenColor);
    }
}

void BottomWidget::setRainbow(bool rainbow) {
    BottomWidget::ranbow = rainbow;
}

void BottomWidget::setColor(QColor color) {
    BottomWidget::pen->setColor(color);
}






