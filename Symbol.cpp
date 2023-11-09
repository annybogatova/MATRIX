//
// Created by AnnyB on 25.10.2023.
//

#include "Symbol.h"
#include <Windows.h>
#include <cstdlib>
#include <random>

char Symbol::SetValue() const{
    int n = 33 + rand()%(126-33);

    if(EpilepsyMode){
        SetTextColor();
    } else {
        SetColor(2); //green
    }
    return char(n);
}


void Symbol::SetColor(int text) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut,(WORD)(text));
}

void Symbol::SetTextColor() {
    int i = 1 + rand()%15;
    SetColor(i);
}

Symbol::Symbol(bool epilepsyMode) : EpilepsyMode(epilepsyMode) {}

Symbol::~Symbol() = default;
