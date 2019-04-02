//
// Created by julien on 16-03-19.
//

#ifndef MANDALA_DRAWINGAREAWIDGET_HPP
#define MANDALA_DRAWINGAREAWIDGET_HPP


#include <QGraphicsView>
#include <include/model/Drawer.hpp>

class DrawingAreaWidget : public QWidget {
Q_OBJECT
public:
    explicit DrawingAreaWidget(QWidget *parent = 0);

    bool openImage(const QString &fileName);

    bool saveImage(const QString &fileName);

private:
    QPoint lastPoint;
    Drawing commandInvoker;
    QPen *pen;
    QPen *gridPen;
    QPen *mirrorPen;
    QPen *erasePen;
    bool grid = false;
    int gridNumber = 1;
    float gridOpacity = 1.0;
    bool mirror = false;
    bool rainbow = false;
    bool erase = false;
    bool line = false;


    void drawLineTo(const QPoint &endPoint, QPen pen);

    void resizeImage(const QSize &newSize);

    void resizeFilter(const QSize &newSize);

    void displayGrid();

    void clearGrid();

protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;


signals:


public slots:
    void clearImage();

    void undo();

    void redo();

    void saveCurrentImage();

    void openNewImage();

    void setSize(QSize *size);

    void setGrid(bool grid);

    void setGridSlice(int number);

    void setGridOpacity(int opacity);

    void setMirror(bool mirror);

    void setRainbow(bool rainbow);

    void setBackgroundColor(QColor* color);

    void setErase(bool erase);

    void setLineWidth(int width);

    void setLineMode(bool line);




};


#endif //MANDALA_DRAWINGAREAWIDGET_HPP
