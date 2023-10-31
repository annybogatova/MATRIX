//
// Created by AnnyB on 25.10.2023.
//

#include <Windows.h>
#include <iostream>
#include "Line.h"

struct Line::cs getConsoleSize() {
    struct Line::cs tmp;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdOut, &csbi);
    tmp.width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    tmp.height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    return tmp;
}

void Line::GotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hStdOut, coord);
}

Line::Line(int lineLength, int lineSpeed, bool epilepsyMode) : LineLength(lineLength), LineSpeed(lineSpeed),
                                                               EpilepsyMode(epilepsyMode) {
    conSize = getConsoleSize();
    X = 1 + rand()%(conSize.width - 2);
    Y = conSize.height - 1;
}

void Line::Move() {
    if(Y == 0){
        sc_end = true;
    }
    if (Y > 0){
        Draw();
        Y--;
    }
    if(Y + LineLength + 1 == 1){
        this->~Line();
    } else{
        if(Y <= conSize.height - LineLength){
            if(sc_end){
                Y--;
            }
            Errase();
        }

    }

}

void Line::Draw() {
    GotoXY(X - (Y % 2), Y);
    printf("%c", symbol.SetValue());
    if(Y % 2 == 1){
        GotoXY(X + (Y % 2), Y);
        printf("%c", symbol.SetValue());
    }
}

void Line::Errase() {
    GotoXY(X - ((Y + LineLength) % 2), (Y + LineLength));
    printf(" ");
    if((Y + LineLength) % 2== 1){
        GotoXY(X + ((Y + LineLength) % 2), (Y + LineLength));
        printf(" ");
    }
}
