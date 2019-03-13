//
// Created by chevron on 13/03/19.
//

#ifndef MANDALA_DRAWINGCOMMAND_HPP
#define MANDALA_DRAWINGCOMMAND_HPP


#include <QtGui/QPainter>

class CommandDrawing {
public:
    CommandDrawing(QPainter &painter);

    virtual void draw() = 0;

    virtual void undo() = 0;

protected:
    QPainter &painter;
private:
};


#endif //MANDALA_DRAWINGCOMMAND_HPP
