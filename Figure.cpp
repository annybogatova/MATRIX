//
// Created by AnnyB on 14.11.2023.
//

#include <cstdio>
#include "Figure.h"

void Figure::Draw(int x, int y, char symbol) {
    if(x > 0 && x < windows.getConsoleSize().width && y > 0 && y < windows.getConsoleSize().height){
        windows.GotoXY(x, y);
        printf("%c", symbol);
    }
}

const std::pair<int, int> &Figure::getCoordinates() {
    coordinates.first = X;
    coordinates.second = Y;
    return coordinates;
}
