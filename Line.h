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
    struct cs conSize = windows.getConsoleSize();

    Symbol symbol = *new Symbol(EpilepsyMode);
    std::chrono::time_point<std::chrono::steady_clock> startClock, endClock;

    void Draw();
    void Erase();
    void Move();


public:
    Line(int lineLength, int lineSpeed, int explosionProbability, bool epilepsyMode);
    void TryMove() override;

    ~Line() {symbol.~Symbol();}
};


#endif //MATRIX_LINE_H
