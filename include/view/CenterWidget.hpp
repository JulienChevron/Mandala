//
// Created by chevron on 12/03/19.
//

#ifndef MANDALA_MIDDLEWIDGET_HPP
#define MANDALA_MIDDLEWIDGET_HPP


#include <QtWidgets/QWidget>
#include "ui_CenterWidget.h"


class CenterWidget : public QWidget {

Q_OBJECT
public:
    explicit CenterWidget(QWidget *parent = 0);

private:
    Ui::CenterWidget *ui;


signals:

public slots:


};


#endif //MANDALA_MIDDLEWIDGET_HPP
