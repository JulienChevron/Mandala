//
// Created by chopinet on 13/03/19.
//

#include "include/model/CommandDrawDot.hpp"

void CommandDrawDot::draw(QPainter &painter) const {
    painter.setPen(pen);
    painter.drawPoint(this->coord);
}

CommandDrawDot::CommandDrawDot(const QPoint &coord, const QPen &pen) :
        coord(coord),
        pen(pen) {}
