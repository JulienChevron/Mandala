//
// Created by julien on 15-03-19.
//

#include "include/model/QPenSingleton.hpp"

QPen *QPenSingleton::pen = nullptr;

QPen *QPenSingleton::Instance() {
    if(!pen){
        pen = new QPen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    }
    return pen;
}
