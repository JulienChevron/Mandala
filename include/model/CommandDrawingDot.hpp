//
// Created by chopinet on 13/03/19.
//

#ifndef MANDALA_COMMANDDRAWINGPOINT_HPP
#define MANDALA_COMMANDDRAWINGPOINT_HPP

#include "model/CommandDrawing.hpp"

class CommandDrawingDot : public CommandDrawing {
public:
    CommandDrawingDot(const QPoint &coord, const QPen &pen);

    void draw(QPainter &painter) override;

    void undo(QPainter &painter) override;

private:
    const QPoint &coord;
    const QPen &pen;
};


#endif //MANDALA_COMMANDDRAWINGPOINT_HPP
