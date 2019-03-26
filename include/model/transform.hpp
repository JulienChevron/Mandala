//
// Created by chopinet on 26/03/19.
//

#ifndef MANDALA_TRANSFORM_HPP
#define MANDALA_TRANSFORM_HPP

#include <QPoint>
#include <QTransform>

QPoint rotatePoint(const QPoint &point, const QPoint &center, int degree) {
    return QTransform()
            .translate(center.x(), center.y())
            .rotate(degree)
            .translate(-center.x(), -center.y())
            .map(point);
}

#endif //MANDALA_TRANSFORM_HPP
