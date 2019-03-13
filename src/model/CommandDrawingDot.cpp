//
// Created by chopinet on 13/03/19.
//

#include "include/model/CommandDrawingDot.hpp"

void CommandDrawingDot::draw(QPainter &painter) {
    painter.save();
    painter.setPen(pen);
    painter.drawPoint(this->coord);
}

void CommandDrawingDot::undo(QPainter &painter) {
    painter.restore();
}

CommandDrawingDot::CommandDrawingDot(const QPoint &coord, const QPen &pen) :
        coord(coord),
        pen(pen) {}
