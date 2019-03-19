//
// Created by julien on 16-03-19.
//

#ifndef MANDALA_DRAWINGAREAWIDGET_HPP
#define MANDALA_DRAWINGAREAWIDGET_HPP


#include <QtWidgets/QGraphicsView>
#include <include/model/Drawing.hpp>

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
    bool grid;
    int gridNumber = 1;
    int gridOpacity;
    bool mirror;
    bool lgbt;

    void drawLineTo(const QPoint &endPoint, QPen pen);

    void resizeImage(QImage *image, const QSize &newSize);


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

    void setSize(QSize *size);

    void setGrid(bool grid);

    void setGridSlice(int number);

    void setGridOpacity(int opacity);

    void setMirror(bool mirror);

    void setLGBT(bool lgbt);

    QPoint rotatePoint(const QPoint &point, const QPoint &center, int degree) const;



};


#endif //MANDALA_DRAWINGAREAWIDGET_HPP
