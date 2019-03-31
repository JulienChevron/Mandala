//
// Created by chopinet on 26/03/19.
//

#ifndef MANDALA_COMMANDDRAWMANDALA_HPP
#define MANDALA_COMMANDDRAWMANDALA_HPP


#include <include/model/transform.hpp>
#include <include/model/CommandDrawLine.hpp>
#include <include/model/CommandDraw.hpp>

class CommandDrawMandala : public CommandDraw {
private:
    const QPoint &coord1;
    const QPoint &coord2;
    const QPoint &center;
    uint grid_number;
    const QPen &pen;
    bool color_rainbow;
    bool mirror;
public:

protected:
public:
    CommandDrawMandala(const QPoint &coord1, const QPoint &coord2, const QPoint &center, uint grid_number,
                       const QPen &pen, bool color_rainbow, bool mirror);

protected:
    void draw(QPainter &painter) const override;
};


#endif //MANDALA_COMMANDDRAWMANDALA_HPP
