//
// Created by chevron on 12/03/19.
//

#ifndef MANDALA_MIDDLEWIDGET_HPP
#define MANDALA_MIDDLEWIDGET_HPP


#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>
#include <include/model/Drawing.hpp>
#include "ui_CenterWidget.h"


class CenterWidget : public QWidget {

Q_OBJECT
public:
    explicit CenterWidget(QWidget *parent = 0);
    bool openImage(const QString &fileName);
    bool saveImage(const QString &fileName, const char *fileFormat);
    void setPenColor(const QColor &newColor);
    void setPenWidth(int newWidth);
    bool isModified() const { return modified; }
    QColor penColor() const { return myPenColor; }
    int penWidth() const { return myPenWidth; }

private:
    Ui::CenterWidget *ui;
    bool modified;
    bool scribbling;
    int myPenWidth;
    QColor myPenColor;
    QPoint lastPoint;
    Drawing commandInvoker;

    void drawLineTo(const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);


protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;


signals:

public slots:
    void clearImage();

};


#endif //MANDALA_MIDDLEWIDGET_HPP
