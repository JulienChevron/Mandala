//
// Created by chopinet on 13/03/19.
//

#ifndef MANDALA_COMMANDDRAWINGPOINT_HPP
#define MANDALA_COMMANDDRAWINGPOINT_HPP

#include "model/CommandDrawing.hpp"

class CommandDrawingDot : public CommandDrawing {
public:
    CommandDrawingDot(QPainter &painter, const QPoint &coord, const QPen &pen);

    void draw() override;

    void undo() override;

private:
    const QPoint &coord;
    const QPen &pen;
};


#endif //MANDALA_COMMANDDRAWINGPOINT_HPP
