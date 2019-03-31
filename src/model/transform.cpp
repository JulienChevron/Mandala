//
// Created by chevron on 26/03/19.
//

#include <include/model/transform.hpp>
#include <cmath>

QPoint rotatePoint(const QPoint &point, const QPoint &center, int degree) {
    return QTransform()
            .translate(center.x(), center.y())
            .rotate(degree)
            .translate(-center.x(), -center.y())
            .map(point);
}

QPoint mirrorPoint(const QPoint &point, const QPoint &center){
    QTransform transform;
    QPoint final;
    transform.rotate(180);
    transform.translate(-(center.x()*2),0);
    final = transform.map(point);
    return QPoint(final.x(), -final.y());
}
