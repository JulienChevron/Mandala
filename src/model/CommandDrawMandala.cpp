//
// Created by chopinet on 26/03/19.
//

#include <include/model/CommandDrawMandala.hpp>
#include <iostream>

void CommandDrawMandala::draw(QPainter &painter) const {
    double angle = 360.0 / this->grid_number;
    QColor color = pen.color();
    QPen qpen = pen;
    int h, s, v, a;
    color.getHsv(&h, &s, &v, &a);
    for (int i = 0; i < grid_number; ++i) {
        QPoint lastPointRotated = rotatePoint(coord1, center, static_cast<int>(angle * i));
        QPoint endPointRotated = rotatePoint(coord2, center, static_cast<int>(angle * i));
        if (color_rainbow) {
            color.setHsv(static_cast<int>(h + angle * i), s, v, a);
            qpen.setColor(color);
        }
        if (mirror) {
            QPoint lastPointMirror = mirrorPoint(lastPointRotated, center);
            QPoint endPointMirror = mirrorPoint(endPointRotated, center);
            CommandDrawLine(lastPointMirror, endPointMirror, qpen).draw_command(painter);
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
        bool color_rainbow,
        bool mirror) :
        coord1(coord1),
        coord2(coord2),
        center(center),
        grid_number(grid_number),
        pen(pen),
        color_rainbow(color_rainbow),
        mirror(mirror) {}





