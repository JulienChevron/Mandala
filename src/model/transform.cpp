//
// Created by chevron on 26/03/19.
//

#include <include/model/transform.hpp>

QPoint rotatePoint(const QPoint &point, const QPoint &center, int degree) {
    return QTransform()
            .translate(center.x(), center.y())
            .rotate(degree)
            .translate(-center.x(), -center.y())
            .map(point);
}
