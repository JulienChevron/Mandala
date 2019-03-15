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
        pen(QPenSingleton::Instance()),
        ui(new Ui::CenterWidget) {
    ui->setupUi(this);
    setAttribute(Qt::WA_StaticContents);
}

bool CenterWidget::openImage(const QString &fileName) {
    QImage loadedImage;
    if (!loadedImage.load(fileName))
        return false;

    QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    commandInvoker.setCurrentImage(loadedImage);
    update();
    return true;
}

bool CenterWidget::saveImage(const QString &fileName) {
    QImage visibleImage = commandInvoker.getCurrentImage();
    resizeImage(&visibleImage, size());
    return visibleImage.save(fileName);
}

void CenterWidget::clearImage() {
    commandInvoker.getCurrentImage().fill(qRgb(255, 255, 255));
    update();
}

void CenterWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        commandInvoker.save();
    }
}

void CenterWidget::mouseMoveEvent(QMouseEvent *event) {
    if ((event->buttons() & Qt::LeftButton))
        drawLineTo(event->pos());
}

void CenterWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        drawLineTo(event->pos());
    }
}

void CenterWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, commandInvoker.getCurrentImage(), dirtyRect);
}

void CenterWidget::drawLineTo(const QPoint &endPoint) {

    CommandDrawLine c(lastPoint, endPoint, *pen);
    commandInvoker.draw(c);
    update();
    lastPoint = endPoint;
}

void CenterWidget::resizeImage(QImage *image, const QSize &newSize) {
    if (image->size() == newSize)
        return;
    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void CenterWidget::undo() {
    std::cout << "undo" << std::endl;
    commandInvoker.undo();
    update();
}

void CenterWidget::redo() {
    std::cout << "redo" << std::endl;
    commandInvoker.redo();
    update();
}

void CenterWidget::saveCurrentImage() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image"), tr("image.png"), tr("Images (*.png *.jpg)"));
    std::cout << fileName.toStdString() << std::endl;
    saveImage(fileName);
}

void CenterWidget::setSize(QSize* size) {
    this->imgSize = size;
    resizeImage(&commandInvoker.getCurrentImage(), *size);
    clearImage();
}


void CenterWidget::setGrid(bool grid) {
    std::cout << "set grid to : " << grid << std::endl;
    this->grid = grid;
}

void CenterWidget::setGridSlice(int number) {
    std::cout << "set grid slice to : " << number << std::endl;
    this->gridNumber = number;
}

void CenterWidget::setGridOpacity(int opacity) {
    std::cout << "set grid slice to : " << opacity << std::endl;
    this->gridOpacity = opacity;
}

void CenterWidget::setMirror(bool mirror) {
    std::cout << "set mirror : " << mirror << std::endl;
    this->mirror = mirror;
}
