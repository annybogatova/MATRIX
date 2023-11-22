//
// Created by AnnyB on 25.10.2023.
//

#ifndef MATRIX_LINE_H
#define MATRIX_LINE_H


#include <chrono>
#include "Symbol.h"
#include "cs.h"
#include "Windows.h"
#include "Figure.h"

class Line: public Figure{

private:

    int LineLength;
    double LineSpeed;
    int ExplosionProbability;
    bool EpilepsyMode;

    bool sc_end = false;
    Windows win;

    void Draw();
    void Erase();
    void Move();

    Symbol symbol = *new Symbol(EpilepsyMode);
    std::chrono::time_point<std::chrono::steady_clock> startClock, endClock;

public:

    struct cs conSize;
    Line(int lineLength, int lineSpeed, int explosionProbability, bool epilepsyMode);
    ~Line() {symbol.~Symbol();}

    void TryMove() override;

};


#endif //MATRIX_LINE_H
