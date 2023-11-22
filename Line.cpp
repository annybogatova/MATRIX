//
// Created by AnnyB on 25.10.2023.
//

#include <iostream>
#include "Line.h"


Line::Line(int lineLength, int lineSpeed, int explosionProbability, bool epilepsyMode)
        : LineLength(lineLength), LineSpeed((double)1.0 / lineSpeed), ExplosionProbability(explosionProbability), EpilepsyMode(epilepsyMode) {
    conSize = win.getConsoleSize();
    X = 1 + rand()%(conSize.width - 2);
    Y = conSize.height - 1;
}

void Line::TryMove() {
    isExplod = false;
    endClock = std::chrono::steady_clock::now();
    if(std::chrono::duration<double>(endClock - startClock).count() >= LineSpeed && !EOL){
        Move();
        if(rand()%1000 <= ExplosionProbability){
            isExplod = true;
        }
        startClock = std::chrono::steady_clock::now();
    }
}


void Line::Move() {
    if (Y == 0) {
        sc_end = true;
    }
    if (Y > 0) {
        Draw();
        Y--;
    }
    if (Y + LineLength == 1) {
        EOL = true;
        this->~Line();
    } else {
        if (Y <= conSize.height - LineLength) {
            if (sc_end) {
                Y--;
            }
            Erase();
        }
    }
}

void Line::Draw() {
    Figure::Draw(X - (Y % 2), Y, symbol.SetValue());
    if(Y % 2 == 1){
        Figure::Draw(X + (Y % 2), Y, symbol.SetValue());
    }
}

void Line::Erase() {
    Figure::Draw(X - ((Y + LineLength) % 2), (Y + LineLength), ' ');
    if((Y + LineLength) % 2 == 1){
        Figure::Draw(X + ((Y + LineLength) % 2), (Y + LineLength), ' ');
    }
}
