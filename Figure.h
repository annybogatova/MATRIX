//
// Created by AnnyB on 14.11.2023.
//

#ifndef MATRIX_FIGURE_H
#define MATRIX_FIGURE_H


#include "Windows.h"
#include "Symbol.h"

class Figure {
    Windows windows;
public:
    void Draw(int x, int y, char symbol);
    virtual void TryMove();
};


#endif //MATRIX_FIGURE_H
