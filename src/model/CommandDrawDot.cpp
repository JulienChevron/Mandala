//
// Created by chopinet on 13/03/19.
//

#include "include/model/CommandDrawDot.hpp"

void CommandDrawDot::draw(QPainter &painter) {
    painter.setPen(pen);
    painter.drawPoint(this->coord);
}

void CommandDrawDot::undo(QPainter &painter) {
}

CommandDrawDot::CommandDrawDot(const QPoint &coord, const QPen &pen) :
        coord(coord),
        pen(pen) {}
