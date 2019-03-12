//

// Created by chevron on 12/03/19.
//

#include "CenterWidget.hpp"


CenterWidget::CenterWidget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::CenterWidget)
{
    ui->setupUi(this);
}