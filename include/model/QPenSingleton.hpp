//
// Created by julien on 15-03-19.
//

#ifndef MANDALA_QPENSINGLETON_H
#define MANDALA_QPENSINGLETON_H


#include <QtGui/QPen>

class QPenSingleton {

public:
    static QPen *Instance();

private:
    static QPen *pen;

};


#endif //MANDALA_QPENSINGLETON_H
