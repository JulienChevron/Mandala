//
// Created by chevron on 13/03/19.
//

#include <include/model/CommandDraw.hpp>


CommandDraw::CommandDraw() = default;

void CommandDraw::draw_command(QPainter &painter) {
    //painter.save();
    draw(painter);
}

void CommandDraw::undo_command(QPainter &painter) {
    undo(painter);
    //painter.restore();
}