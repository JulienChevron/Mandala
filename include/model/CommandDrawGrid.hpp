//
// Created by chevron on 26/03/19.
//

#ifndef MANDALA_COMMANDDRAWGRID_HPP
#define MANDALA_COMMANDDRAWGRID_HPP


#include "CommandDraw.hpp"

class CommandDrawGrid : public CommandDraw {

public:
    CommandDrawGrid(const QPoint &coord1, const QPoint &coord2, const QPen &pen, int number, int opacity);

protected:
    void draw(QPainter &painter) const override;

private:
    const QPoint &center;
    const QPoint &first;
    const QPen &pen;
    const int number;
    const int opacity;

};


#endif //MANDALA_COMMANDDRAWGRID_HPP
