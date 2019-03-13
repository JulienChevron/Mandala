//
// Created by chevron on 13/03/19.
//

#include <include/model/CommandDrawing.hpp>


CommandDrawing::CommandDrawing() = default;

void CommandDrawing::draw_command(QPainter &painter) {
    painter.save();
    draw(painter);
}

void CommandDrawing::undo_command(QPainter &painter) {
    undo(painter);
    painter.restore();
}