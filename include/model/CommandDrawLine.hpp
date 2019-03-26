//
// Created by pierre on 13/03/19.
//

#ifndef MANDALA_COMMANDDRAWLINE_HPP
#define MANDALA_COMMANDDRAWLINE_HPP


#include <include/model/CommandDraw.hpp>

class CommandDrawLine : public CommandDraw {
public:
    CommandDrawLine(const QPoint &coord1, const QPoint &coord2, const QPen &pen);

protected:
    void draw(QPainter &painter) const override;

private:
    const QPoint &coord1;
    const QPoint &coord2;
    const QPen &pen;
};


#endif //MANDALA_COMMANDDRAWLINE_HPP
