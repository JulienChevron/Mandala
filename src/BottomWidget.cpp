//
// Created by chevron on 12/03/19.
//

#include "include/BottomWidget.hpp"

BottomWidget::BottomWidget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::BottomWidget)
{
    ui->setupUi(this);
}
