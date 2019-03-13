//

// Created by chevron on 12/03/19.
//

#include "include/view/CenterWidget.hpp"


CenterWidget::CenterWidget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::CenterWidget)
{
    ui->setupUi(this);
}
