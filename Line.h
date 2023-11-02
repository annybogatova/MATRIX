//
// Created by AnnyB on 25.10.2023.
//

#ifndef MATRIX_LINE_H
#define MATRIX_LINE_H


#include "Symbol.h"

class Line {

private:
    int LineLength;
    bool EpilepsyMode;

    int X = 0;
    int Y = 0;
    bool sc_end = false;

    void Draw();
    void Erase();

    Symbol symbol = *new Symbol(EpilepsyMode);

public:
    Line(int lineLength, bool epilepsyMode);

    void Move();

    struct cs
    {
        int width;
        int height;
    };
    struct cs conSize;
    void GotoXY(int x, int y);
    bool EOL = false;

    ~Line() {symbol.~Symbol();}
};


#endif //MATRIX_LINE_H
