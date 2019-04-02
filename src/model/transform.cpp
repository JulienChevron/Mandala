//
// Created by chevron on 26/03/19.
//

#include <include/model/transform.hpp>
#include <cmath>

QPoint rotatePoint(const QPoint &point, const QPoint &center, double degree) {
    return QTransform()
            .translate(center.x(), center.y())
            .rotate(degree)
            .translate(-center.x(), -center.y())
            .map(point);
}

QPoint mirrorPoint(const QPoint &point, const QPoint &center) {

    return QTransform()
            .translate(center.x(), center.y())
            .scale(1, -1)
            .translate(-center.x(), -center.y())
            .map(point);
}
