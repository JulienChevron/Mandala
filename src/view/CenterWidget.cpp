//

// Created by chevron on 12/03/19.
//

#include <QtGui/QPainter>
#include <QMouseEvent>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <include/view/CenterWidget.hpp>
#include <include/model/CommandDrawLine.hpp>
#include <iostream>
#include <QtWidgets/QFileDialog>
#include <include/model/QPenSingleton.hpp>


CenterWidget::CenterWidget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::CenterWidget) {
    ui->setupUi(this);
    layout()->setAlignment(this, Qt::AlignCenter);
    setAttribute(Qt::WA_StaticContents);
    setStyleSheet("border: 2px solid black");
}


Ui::CenterWidget *CenterWidget::getUi() const {
    return ui;
}