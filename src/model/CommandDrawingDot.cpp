//
// Created by chopinet on 13/03/19.
//

#include "include/model/CommandDrawingDot.hpp"

void CommandDrawingDot::draw() {
    painter.save();
    painter.setPen(pen);
    painter.drawPoint(this->coord);
}

void CommandDrawingDot::undo() {
    painter.restore();
}

CommandDrawingDot::CommandDrawingDot(QPainter &painter, const QPoint &coord, const QPen &pen) : CommandDrawing(painter),
                                                                                                coord(coord),
                                                                                                pen(pen) {}
