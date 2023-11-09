//
// Created by AnnyB on 02.11.2023.
//

#ifndef MATRIX_WINDOWS_H
#define MATRIX_WINDOWS_H


#include "cs.h"

class Windows {

public:
    struct cs getConsoleSize();
    void GotoXY(int x, int y);
    void clean();

    void cls(void *hConsole);

    void hidecursor();
};


#endif //MATRIX_WINDOWS_H
