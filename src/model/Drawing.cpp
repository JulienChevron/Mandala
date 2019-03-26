//
// Created by chevron on 13/03/19.
//

#include <include/model/Drawing.hpp>
#include <iostream>

#define MAX_UNDO 100

void Drawing::draw(const CommandDraw &commandDrawing) {
    QPainter painter(&currentImage);
    commandDrawing.draw_command(painter);
    dequeImageRedo.clear();
}


void Drawing::drawOnFilter(const CommandDraw &commandDrawing) {
    QPainter painter(&filter);
    commandDrawing.draw_command(painter);
}

Drawing::Drawing() : dequeImageUndo(), dequeImageRedo() {
}

Drawing::~Drawing() {
}

void Drawing::undo() {
    dequeImageRedo.push_back(currentImage);
    if (dequeImageRedo.size() > MAX_UNDO) {
        dequeImageRedo.erase(dequeImageRedo.begin());
    }
    if (!dequeImageUndo.empty()) {
        currentImage = dequeImageUndo.back();
        dequeImageUndo.erase(dequeImageUndo.end());
    }
}

void Drawing::redo() {
   save();
    if (!dequeImageRedo.empty()) {
        currentImage = dequeImageRedo.back();
        dequeImageRedo.erase(dequeImageRedo.end());
    }
}

QImage &Drawing::getCurrentImage() {
    return currentImage;
}

QImage &Drawing::getFilterImage() {
    return filter;
}

void Drawing::setCurrentImage(const QImage &currentImage) {
    this->currentImage = currentImage;
}


void Drawing::setFilterImage(const QImage &filterImage) {
    this->filter = filterImage;
}

void Drawing::save() {
    dequeImageUndo.push_back(currentImage);
    if (dequeImageUndo.size() > MAX_UNDO) {
        dequeImageUndo.erase(dequeImageUndo.begin());
    }
}

void Drawing::clearImage() {
    getCurrentImage().fill(qRgb(255, 255, 255));
}

void Drawing::clearFilter() {

}



