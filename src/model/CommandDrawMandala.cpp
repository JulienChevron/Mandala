//
// Created by chopinet on 26/03/19.
//

#include <include/model/CommandDrawMandala.hpp>

void CommandDrawMandala::draw(QPainter &painter) const {
    int angle = 360 / this->grid_number;
    QColor color = pen.color();
    QPen qpen = pen;
    int h, s, v, a;
    color.getHsv(&h, &s, &v, &a);
    for (int i = 0; i < grid_number; ++i) {
        QPoint lastPointRotated = rotatePoint(coord1, center, angle * i);
        QPoint endPointRotated = rotatePoint(coord2, center, angle * i);
        if (color_rainbow) {
            color.setHsv((h + angle * i), s, v, a);
            qpen.setColor(color);
        }
        CommandDrawLine(lastPointRotated, endPointRotated, qpen).draw_command(painter);
    }
}

CommandDrawMandala::CommandDrawMandala(
        const QPoint &coord1,
        const QPoint &coord2,
        const QPoint &center,
        uint grid_number,
        const QPen &pen,
        bool color_rainbow) :
        coord1(coord1),
        coord2(coord2),
        center(center),
        grid_number(grid_number),
        pen(pen),
        color_rainbow(color_rainbow) {}





