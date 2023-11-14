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
    bool EpilepsyMode;

    int X = 0;
    int Y = 0;
    bool sc_end = false;
    Windows win;

    void Draw();
    void Erase();

    Symbol symbol = *new Symbol(EpilepsyMode);
    std::chrono::time_point<std::chrono::steady_clock> startClock, endClock;

public:
    void Move();

    struct cs conSize;
    bool EOL = false;
    Line(int lineLength, int lineSpeed, bool epilepsyMode);
    ~Line() {symbol.~Symbol();}

    void tryMove();
};


#endif //MATRIX_LINE_H
