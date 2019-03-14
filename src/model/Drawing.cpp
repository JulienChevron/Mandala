//
// Created by chevron on 13/03/19.
//

#include <include/model/Drawing.hpp>

#include "include/model/Drawing.hpp"

void Drawing::draw(CommandDraw &commandDrawing) {
    stackImageUndo.push(currentImage);
    QPainter painter(&currentImage);
    commandDrawing.draw_command(painter);
}

Drawing::Drawing() : stackImageUndo(), stackImageRedo() {
}

Drawing::~Drawing() {
}

void Drawing::undo() {
    stackImageRedo.push(currentImage);
    currentImage = stackImageUndo.top();
    stackImageUndo.pop();
}

void Drawing::redo() {
    stackImageUndo.push(currentImage);
    currentImage = stackImageRedo.top();
    stackImageRedo.pop();
}

QImage & Drawing::getCurrentImage() {
    return currentImage;
}

void Drawing::setCurrentImage(const QImage &currentImage) {
    this->currentImage = currentImage;
}
