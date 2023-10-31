//
// Created by AnnyB on 25.10.2023.
//

#ifndef MATRIX_LINE_H
#define MATRIX_LINE_H


#include "Symbol.h"

class Line {

private:
    int LineLength;
    int LineSpeed;
    bool EpilepsyMode;

    int X = 0;
    int Y = 0;
    bool sc = true;
    bool sc_end = false;

    void Draw();
    void Errase();

    Symbol symbol = *new Symbol(EpilepsyMode);

public:
    Line(int lineLength, int lineSpeed, bool epilepsyMode);

    void Move();

    struct cs
    {
        int width;
        int height;
    };
    struct cs conSize;
    void GotoXY(int x, int y);

    ~Line() {symbol.~Symbol();}
};


#endif //MATRIX_LINE_H
