//
// Created by chevron on 12/03/19.
//

#ifndef MANDALA_TOPWIDGET_HPP
#define MANDALA_TOPWIDGET_HPP


#include <QtWidgets/QWidget>
#include "ui_TopWidget.h"

class TopWidget : public QWidget{

Q_OBJECT
public:
    TopWidget(QWidget *parent = 0);

private:
    Ui::TopWidget *ui;

signals:

public slots:

};


#endif //MANDALA_TOPWIDGET_HPP
