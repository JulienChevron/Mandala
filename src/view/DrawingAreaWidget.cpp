//
// Created by julien on 16-03-19.
//

#include <QtGui/QPainter>
#include <QMouseEvent>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <include/view/DrawingAreaWidget.hpp>
#include <include/model/CommandDrawLine.hpp>
#include <iostream>
#include <QtWidgets/QFileDialog>
#include <include/model/QPenSingleton.hpp>


DrawingAreaWidget::DrawingAreaWidget(QWidget *parent) :
        QWidget(parent),
        pen(QPenSingleton::Instance()){
    setAttribute(Qt::WA_StaticContents);
}

bool DrawingAreaWidget::openImage(const QString &fileName) {
    QImage loadedImage;
    if (!loadedImage.load(fileName))
        return false;

    QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    commandInvoker.setCurrentImage(loadedImage);
    update();
    return true;
}

bool DrawingAreaWidget::saveImage(const QString &fileName) {
    QImage visibleImage = commandInvoker.getCurrentImage();
    //resizeImage(&visibleImage, *this->imgSize);
    return visibleImage.save(fileName);
}

void DrawingAreaWidget::clearImage() {
    commandInvoker.getCurrentImage().fill(qRgb(255, 255, 255));
    update();
}

void DrawingAreaWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        commandInvoker.save();
    }
}

void DrawingAreaWidget::mouseMoveEvent(QMouseEvent *event) {
    if ((event->buttons() & Qt::LeftButton))
        drawLineTo(event->pos(), *pen);
}

void DrawingAreaWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        drawLineTo(event->pos(), *pen);
    }
}

void DrawingAreaWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, commandInvoker.getCurrentImage(), dirtyRect);
}

void DrawingAreaWidget::drawLineTo(const QPoint &endPoint, QPen pen) {
    QPoint center(imgSize->width() / 2, imgSize->height() / 2);
    int angle = 360 / this->gridNumber;
    if (gridNumber == 1 or !mirror) {
        commandInvoker.draw(CommandDrawLine(lastPoint, endPoint, pen));
    } else {
        QColor color = pen.color();
        int h, s, v, a;
        color.getHsv(&h, &s, &v, &a);
        for (int i = 0; i < gridNumber; ++i) {
            QPoint lastPointRotated = rotatePoint(lastPoint, center, angle * i);
            QPoint endPointRotated = rotatePoint(endPoint, center, angle * i);
            if (lgbt) {
                color.setHsv((h + angle * i), s, v, a);
                pen.setColor(color);
            }
            commandInvoker.draw(CommandDrawLine(lastPointRotated, endPointRotated, pen));
        }
    }
    update();
    lastPoint = endPoint;
}

QPoint DrawingAreaWidget::rotatePoint(const QPoint &point, const QPoint &center, int degree) const {
    return QTransform()
            .translate(center.x(), center.y())
            .rotate(degree)
            .translate(-center.x(), -center.y())
            .map(point);
}

void DrawingAreaWidget::resizeImage(QImage *image, const QSize &newSize) {
    if (image->size() == newSize)
        return;
    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void DrawingAreaWidget::undo() {
    std::cout << "undo" << std::endl;
    commandInvoker.undo();
    update();
}

void DrawingAreaWidget::redo() {
    std::cout << "redo" << std::endl;
    commandInvoker.redo();
    update();
}

void DrawingAreaWidget::saveCurrentImage() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image"), tr("image.png"),
                                                    tr("Images (*.png *.jpg)"));
    std::cout << fileName.toStdString() << std::endl;
    saveImage(fileName);
}

void DrawingAreaWidget::setSize(QSize *size) {
    this->imgSize = size;
    setMinimumSize(*size);
    setMaximumSize(*size);
    resizeImage(&commandInvoker.getCurrentImage(), *size);
    clearImage();
}


void DrawingAreaWidget::setGrid(bool grid) {
    std::cout << "set grid to : " << grid << std::endl;
    this->grid = grid;
}

void DrawingAreaWidget::setGridSlice(int number) {
    std::cout << "set grid slice to : " << number << std::endl;
    this->gridNumber = number;
}

void DrawingAreaWidget::setGridOpacity(int opacity) {
    std::cout << "set grid opacity to : " << opacity << std::endl;
    this->gridOpacity = opacity;
}

void DrawingAreaWidget::setMirror(bool mirror) {
    std::cout << "set mirror : " << mirror << std::endl;
    this->mirror = mirror;
}

void DrawingAreaWidget::setLGBT(bool lgbt) {
    std::cout << "set lgbt : " << mirror << std::endl;
    this->lgbt = lgbt;
}
