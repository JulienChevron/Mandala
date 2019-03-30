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
#include <include/model/CommandDrawGrid.hpp>

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
    resizeImage(newSize);
    commandInvoker.setCurrentImage(loadedImage);
    update();
    return true;
}

bool DrawingAreaWidget::saveImage(const QString &fileName) {
    QImage visibleImage = commandInvoker.getCurrentImage();
    return visibleImage.save(fileName);
}

void DrawingAreaWidget::clearImage() {
    commandInvoker.clearImage();
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
    if (grid)
        painter.drawImage(dirtyRect, commandInvoker.getFilterImage(), dirtyRect);
}

void DrawingAreaWidget::drawLineTo(const QPoint &endPoint, QPen pen) {
    QPoint center(commandInvoker.getCurrentImage().width() / 2, commandInvoker.getCurrentImage().height() / 2);
    if (gridNumber == 1) {
        commandInvoker.draw(CommandDrawLine(lastPoint, endPoint, pen));
    } else {
        commandInvoker.draw(
                CommandDrawMandala(lastPoint, endPoint, center, static_cast<uint>(gridNumber), pen, rainbow));
    }
    update();
    lastPoint = endPoint;
}


void DrawingAreaWidget::resizeImage(const QSize &newSize) {
    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), newImage);
    commandInvoker.setCurrentImage(newImage);
    update();
}

void DrawingAreaWidget::undo() {
    commandInvoker.undo();
    update();
}

void DrawingAreaWidget::redo() {
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
    commandInvoker.clearFilter();
    QImage filter(newSize, QImage::Format_ARGB32);
    QPainter painterFilter(&filter);
    commandInvoker.setFilterImage(filter);
    painterFilter.setOpacity(0.0);
    painterFilter.drawImage(QPoint(0, 0), filter);
    displayGrid();
    update();
}

void DrawingAreaWidget::displayGrid() {
    commandInvoker.clearFilter();
    QPoint center(commandInvoker.getFilterImage().width() / 2, commandInvoker.getFilterImage().width() / 2);
    QPoint first(-(commandInvoker.getFilterImage().width() * 2), commandInvoker.getFilterImage().width() / 2);
    commandInvoker.drawOnFilter(CommandDrawGrid(center, first, *gridPen, gridNumber, gridOpacity));
    update();
}

void DrawingAreaWidget::clearGrid() {
    commandInvoker.clearFilter();
    QSize size = commandInvoker.getFilterImage().size();
    QImage newFilter(size, QImage::Format_ARGB32);
    QPainter painterFilter(&newFilter);
    painterFilter.setOpacity(0.0);
    commandInvoker.setFilterImage(newFilter);
    update();
}

void DrawingAreaWidget::setSize(QSize *size) {
    setMinimumSize(*size);
    setMaximumSize(*size);
    resizeImage(*size);
    resizeFilter(*size);
    clearImage();
    if (grid) {
        displayGrid();
    }
    update();
}

void DrawingAreaWidget::setGrid(bool grid) {
    this->grid = grid;
    if (grid) {
        displayGrid();
    } else {
        clearGrid();
    }
    update();
}

void DrawingAreaWidget::setGridSlice(int number) {
    this->gridNumber = number;
    if (grid) {
        displayGrid();
    }
}

void DrawingAreaWidget::setGridOpacity(int opacity) {
    std::cout << opacity << std::endl;
    QColor color(160, 160, 160, opacity);
    gridPen->brush().setColor(color);
    if (grid) {
        displayGrid();
    }
    update();
}

void DrawingAreaWidget::setMirror(bool mirror) {
    this->mirror = mirror;
}

void DrawingAreaWidget::setRainbow(bool rainbow) {
    this->rainbow = rainbow;
}



