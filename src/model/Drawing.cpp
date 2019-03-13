//
// Created by chevron on 13/03/19.
//

#include "include/model/Drawing.hpp"

void Drawing::drawAll(QPainter &painter) {
    auto end = listCommand.end();
    for (auto it = listCommand.begin(); it != end; ++it) {
        (*it)->draw_command(painter);
    }
}

void Drawing::draw(QPainter &painter, CommandDraw &commandDrawing) {
    commandDrawing.draw_command(painter);
    listCommand.push_back(&commandDrawing);
}

Drawing::Drawing() : listCommand() {
}

Drawing::~Drawing() {
    auto end = listCommand.end();
    for (auto it = listCommand.begin(); it != end; ++it) {
        delete *it;//TODO FIX THAT
    }
}
