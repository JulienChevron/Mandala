//
// Created by chopinet on 26/03/19.
//

#ifndef MANDALA_TRANSFORM_HPP
#define MANDALA_TRANSFORM_HPP

#include <QPoint>
#include <QTransform>

QPoint rotatePoint(const QPoint &point, const QPoint &center, double degree);

QPoint mirrorPoint(const QPoint &point, const QPoint &center);


#endif //MANDALA_TRANSFORM_HPP
