//
// Created by chevron on 13/03/19.
//

#ifndef MANDALA_DRAWING_HPP
#define MANDALA_DRAWING_HPP


#include <stack>
#include <memory>
#include "CommandDraw.hpp"

class Drawing {
public:
    Drawing();

    virtual ~Drawing();

    void draw(CommandDraw &commandDrawing);
    void save();
    void undo();
    void redo();

    QImage & getCurrentImage();

    void setCurrentImage(const QImage &currentImage);

private:
    QImage currentImage;
    std::deque<QImage> dequeImageUndo;
    std::deque<QImage> dequeImageRedo;

};


#endif //MANDALA_DRAWING_HPP
