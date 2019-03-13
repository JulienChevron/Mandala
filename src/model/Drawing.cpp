//
// Created by chevron on 13/03/19.
//

#include <include/model/Drawing.hpp>

#include "include/model/Drawing.hpp"

void Drawing::drawAll(QPainter &painter) {
    auto end = listCommand.end();
    for (auto it = listCommand.begin(); it != end; ++it) {
        (*it).draw(painter);
    }
}

void Drawing::draw(QPainter &painter, CommandDrawing &commandDrawing) {
    commandDrawing.draw(painter);
    listCommand.push_back(commandDrawing);
}

Drawing::Drawing() : listCommand() {
}
