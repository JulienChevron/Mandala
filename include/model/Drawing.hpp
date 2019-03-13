//
// Created by chevron on 13/03/19.
//

#ifndef MANDALA_DRAWING_HPP
#define MANDALA_DRAWING_HPP


#include <list>
#include <memory>
#include "CommandDraw.hpp"

class Drawing {
public:
    Drawing();

    virtual ~Drawing();

    void drawAll(QPainter &painter);
    void draw(QPainter &painter, CommandDraw &commandDrawing);
private:
    std::list<CommandDraw*> listCommand;
};


#endif //MANDALA_DRAWING_HPP
