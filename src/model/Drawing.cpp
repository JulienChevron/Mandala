//
// Created by chevron on 13/03/19.
//

#include <include/model/Drawing.hpp>

#include "include/model/Drawing.hpp"

#define MAX_UNDO 100

void Drawing::draw(CommandDraw &commandDrawing) {
    dequeImageUndo.push_back(currentImage);
    if (dequeImageUndo.size() > MAX_UNDO) {
        dequeImageUndo.erase(dequeImageUndo.begin());
    }
    QPainter painter(&currentImage);
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
    currentImage = dequeImageUndo.back();
    dequeImageUndo.erase(dequeImageUndo.end());
}

void Drawing::redo() {
    dequeImageUndo.push_back(currentImage);
    if (dequeImageUndo.size() > MAX_UNDO) {
        dequeImageUndo.erase(dequeImageUndo.begin());
    }
    currentImage = dequeImageRedo.back();
    dequeImageRedo.erase(dequeImageRedo.end());
}

QImage &Drawing::getCurrentImage() {
    return currentImage;
}

void Drawing::setCurrentImage(const QImage &currentImage) {
    this->currentImage = currentImage;
}
