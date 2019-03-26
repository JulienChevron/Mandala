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
#include <include/model/CommandDrawMandala.hpp>

DrawingAreaWidget::DrawingAreaWidget(QWidget *parent) :
        QWidget(parent),
        pen(QPenSingleton::Instance()),
        gridPen(new QPen(Qt::gray, 10, Qt::DashDotLine)) {
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
    painter.drawImage(dirtyRect, *filter, dirtyRect);
}

void DrawingAreaWidget::drawLineTo(const QPoint &endPoint, QPen pen) {
    QPoint center(commandInvoker.getCurrentImage().width() / 2, commandInvoker.getCurrentImage().height() / 2);
    if (gridNumber == 1) {
        commandInvoker.draw(CommandDrawLine(lastPoint, endPoint, pen));
    } else {
        commandInvoker.draw(CommandDrawMandala(lastPoint, endPoint, center, static_cast<uint>(gridNumber), pen, lgbt));
    }
    update();
    lastPoint = endPoint;
}


void DrawingAreaWidget::resizeImage(QImage *image, const QSize &newSize) {
    if (image->size() == newSize)
        return;
    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
    update();
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

void DrawingAreaWidget::resizeFilter(const QSize &newSize) {
    filter = new QImage(newSize, QImage::Format_ARGB32);
    QPainter painterFilter(filter);
    painterFilter.setOpacity(1.00);
    update();
}

void DrawingAreaWidget::displayGrid() {
    QPoint center(filter->width() / 2, filter->height() / 2);
    QPoint first(-(filter->width() * 2), filter->height() / 2);
    int angle = 360 / this->gridNumber;
    if (gridNumber > 1) {
        /*for (int i = 0; i < gridNumber; ++i) {
            //QPoint lastPointRotated = rotatePoint(first, center, angle * i);
            QPainter painterFilter(filter);
            painterFilter.setPen(*gridPen);
            painterFilter.drawLine(center.x(), center.y(), lastPointRotated.x(), lastPointRotated.y());
        }*/
    }
    update();
}

void DrawingAreaWidget::clearGrid() {
    QSize size = filter->size();
    filter = new QImage(size, QImage::Format_ARGB32);
    QPainter painterFilter(filter);
    painterFilter.setOpacity(1.00);
}

void DrawingAreaWidget::setSize(QSize *size) {
    setMinimumSize(*size);
    setMaximumSize(*size);
    resizeImage(&commandInvoker.getCurrentImage(), *size);
    resizeFilter(*size);
    clearImage();
    if (grid) {
        displayGrid();
    }
}

void DrawingAreaWidget::setGrid(bool grid) {
    this->grid = grid;
    if (grid) {
        displayGrid();
    } else {
        clearGrid();
    }
}

void DrawingAreaWidget::setGridSlice(int number) {
    this->gridNumber = number;
    if (grid) {
        clearGrid();
        displayGrid();
    }
}

void DrawingAreaWidget::setGridOpacity(int opacity) {
    std::cout << opacity << std::endl;
    QColor color(160, 160, 160, opacity);
    gridPen->brush().setColor(color);
    if (grid) {
        clearGrid();
        displayGrid();
    }
}

void DrawingAreaWidget::setMirror(bool mirror) {
    this->mirror = mirror;
}

void DrawingAreaWidget::setLGBT(bool lgbt) {
    this->lgbt = lgbt;
}



