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

void Drawing::setCurrentImage(const QImage &currentImage) {
    this->currentImage = currentImage;
}

void Drawing::save() {
    std::cout << "save" << std::endl;
    dequeImageUndo.push_back(currentImage);
    if (dequeImageUndo.size() > MAX_UNDO) {
        dequeImageUndo.erase(dequeImageUndo.begin());
    }
}
