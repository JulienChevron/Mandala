//
// Created by chevron on 26/03/19.
//

#include <include/model/CommandDrawGrid.hpp>
#include <include/model/transform.hpp>

CommandDrawGrid::CommandDrawGrid(const QPoint &center, const QPoint &first, const QPen &pen, int number, int opacity) :
    center(center), first(first), pen(pen), number(number), opacity(opacity)
{

}

void CommandDrawGrid::draw(QPainter &painter) const {
    int angle = 360 / number;
    if (number > 1) {
        for (int i = 0; i < number; ++i) {
            QPoint lastPointRotated = rotatePoint(first, center, angle * i);
            painter.setPen(pen);
            painter.drawLine(center.x(), center.y(), lastPointRotated.x(), lastPointRotated.y());
        }
    }
}

