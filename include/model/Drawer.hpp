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

    void draw(const CommandDraw &commandDrawing);
    void drawOnFilter(const CommandDraw &commandDrawing);
    void save();
    void undo();
    void redo();

    QImage & getCurrentImage();
    QImage & getFilterImage();

    void setCurrentImage(const QImage &currentImage);
    void setFilterImage(const QImage &filterImage);

    void clearImage();

    void clearFilter();

private:
    QImage currentImage;
    QImage filter;
    std::deque<QImage> dequeImageUndo;
    std::deque<QImage> dequeImageRedo;

};


#endif //MANDALA_DRAWING_HPP
