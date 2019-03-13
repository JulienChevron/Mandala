//
// Created by chevron on 13/03/19.
//

#ifndef MANDALA_DRAWING_HPP
#define MANDALA_DRAWING_HPP


#include <list>
#include <memory>
#include "CommandDrawing.hpp"

class Drawing {
public:
    Drawing();

    virtual ~Drawing();

    void drawAll(QPainter &painter);
    void draw(QPainter &painter, CommandDrawing &commandDrawing);
private:
    std::list<CommandDrawing*> listCommand;
};


#endif //MANDALA_DRAWING_HPP
