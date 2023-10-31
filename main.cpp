#include <iostream>
#include <synchapi.h>
#include "Manager.h"
#include "Line.h"

int main() {
    std::cout << "MATRIX" << std::endl;
    Welcome welcome;
    Line line(5, 10, true);
    for(int i = 0; i < 31+5; i++){
        line.Move();
        Sleep(1000/10);
    }
    std::cin.get();
    return 0;
}
