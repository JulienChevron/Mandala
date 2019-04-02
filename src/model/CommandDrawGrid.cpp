//
// Created by chevron on 26/03/19.
//

#include <include/model/CommandDrawGrid.hpp>
#include <include/model/transform.hpp>
#include <iostream>

CommandDrawGrid::CommandDrawGrid(const QPoint &center, const QPoint &first, const QPen &pen, int number, float opacity)
        :
        center(center), first(first), pen(pen), number(number), opacity(opacity) {}

void CommandDrawGrid::draw(QPainter &painter) const {
    double angle = 360.0 / number;
    if (number > 1) {
        for (int i = 0; i < number; ++i) {
            QPoint lastPointRotated = rotatePoint(first, center, angle * (double) i);
            painter.setPen(pen);
            painter.setOpacity(opacity);
            painter.drawLine(center.x(), center.y(), lastPointRotated.x(), lastPointRotated.y());
        }
    }
}

