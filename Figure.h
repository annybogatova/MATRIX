//
// Created by AnnyB on 14.11.2023.
//

#ifndef MATRIX_FIGURE_H
#define MATRIX_FIGURE_H

#include <tuple>
#include "Windows.h"
#include "Symbol.h"

class Figure {

protected:
    int X, Y;
    std::pair<int,int> coordinates;
    Windows windows;


    char wtype;

public:
    const std::pair<int, int> &getCoordinates();
    void Draw(int x, int y, char symbol);
    virtual void TryMove() = 0;
    bool EOL = false;
    bool isExplod = false;
};


#endif //MATRIX_FIGURE_H
