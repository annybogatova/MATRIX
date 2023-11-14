//
// Created by AnnyB on 25.10.2023.
//

#include <iostream>
#include "Manager.h"
#include "Run.h"

Manager::Manager(){
    srand(time(nullptr));
    setlocale(LC_ALL, "Russian");
    Welcome welcome; //introduce, set parameters
    Windows windows;
    windows.clean();
    Run run(welcome.getLineLength(), welcome.getLineSpeed(), welcome.getLineFrequency(), welcome.isEpilepsyMode());
}
