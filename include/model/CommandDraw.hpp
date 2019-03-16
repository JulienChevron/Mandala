//
// Created by chevron on 13/03/19.
//

#ifndef MANDALA_DRAWINGCOMMAND_HPP
#define MANDALA_DRAWINGCOMMAND_HPP


#include <QtGui/QPainter>

class CommandDraw {
public:
    explicit CommandDraw();
    virtual void draw_command(QPainter & painter) const;
    virtual void undo_command(QPainter & painter);
protected:
    virtual void draw(QPainter &painter) const = 0;

    virtual void undo(QPainter &painter) = 0;

protected:
private:
};


#endif //MANDALA_DRAWINGCOMMAND_HPP
