//
// Created by chevron on 12/03/19.
//

#ifndef MANDALA_BOTTOMWIDGET_HPP
#define MANDALA_BOTTOMWIDGET_HPP


#include <QtWidgets/QWidget>
#include <QPen>
#include "ui_BottomWidget.h"

class BottomWidget : public QWidget {

    Q_OBJECT
public:
    explicit BottomWidget(QWidget *parent = 0);
    Ui::BottomWidget *getUi() const;

private:
    Ui::BottomWidget *ui;
    QPen *pen;
    QGraphicsScene *dotScene;
    bool ranbow;
    void setColor(QColor color);
    void drawDot();

signals:

public slots:
    void setLineWidth(int lineWidth);
    void chooseColor();
    void setRainbow(bool rainbow);
};


#endif //MANDALA_BOTTOMWIDGET_HPP
