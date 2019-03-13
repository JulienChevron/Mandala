//

// Created by chevron on 12/03/19.
//

#include <QtGui/QPainter>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <include/view/CenterWidget.hpp>

#include "include/view/CenterWidget.hpp"


CenterWidget::CenterWidget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::CenterWidget)
{
    ui->setupUi(this);

}

void CenterWidget::paintEvent(QPaintEvent *event) {
    painter = new QPainter(this);
    painter->fillRect(5, 5, width(), height(), Qt::white);
}
