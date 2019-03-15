//
// Created by chevron on 12/03/19.
//

#include <include/view/TopWidget.hpp>

#include "include/view/TopWidget.hpp"


TopWidget::TopWidget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::TopWidget)
{
    ui->setupUi(this);
    ui->dimension->addItem("400x400", QSize(400,400));
    ui->dimension->addItem("600x600", QSize(600,600));
    ui->dimension->addItem("800x600", QSize(800,600));
    ui->dimension->addItem("1280x720", QSize(1280,720));
    ui->dimension->setCurrentText("800x600");
}

Ui::TopWidget *TopWidget::getUi() const {
    return ui;
}

void TopWidget::updateSize(int index) {
    QSize *size = static_cast<QSize *>(ui->dimension->itemData(index).data());
    emit sendSize(size);
}
