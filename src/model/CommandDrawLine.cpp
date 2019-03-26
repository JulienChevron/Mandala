//
// Created by pierre on 13/03/19.
//

#include "include/model/CommandDrawLine.hpp"

void CommandDrawLine::draw(QPainter &painter) const {
    painter.setPen(pen);
    painter.drawLine(coord1, coord2);
}

CommandDrawLine::CommandDrawLine(const QPoint &coord1, const QPoint &coord2, const QPen &pen) : coord1(coord1),
                                                                                                coord2(coord2),
                                                                                                pen(pen) {}
