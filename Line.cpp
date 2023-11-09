//
// Created by AnnyB on 25.10.2023.
//

#include <iostream>
#include "Line.h"



Line::Line(int lineLength, int lineSpeed, bool epilepsyMode) : LineLength(lineLength), LineSpeed((double)1.0 / lineSpeed), EpilepsyMode(epilepsyMode) {
    conSize = win.getConsoleSize();
    X = 1 + rand()%(conSize.width - 2);
    Y = conSize.height - 1;
}

void Line::tryMove(){
    endClock = std::chrono::steady_clock::now();
    if(std::chrono::duration<double>(endClock - startClock).count() >= LineSpeed && !EOL){
        Move();
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
    win.GotoXY(X - (Y % 2), Y);
    printf("%c", symbol.SetValue());
    if(Y % 2 == 1){
        win.GotoXY(X + (Y % 2), Y);
        printf("%c", symbol.SetValue());
    }
}

void Line::Erase() {
    win.GotoXY(X - ((Y + LineLength) % 2), (Y + LineLength));
    printf(" ");
    if((Y + LineLength) % 2 == 1){
        win.GotoXY(X + ((Y + LineLength) % 2), (Y + LineLength));
        printf(" ");
    }
}
