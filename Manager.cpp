//
// Created by AnnyB on 25.10.2023.
//

#include <cstdio>
#include <ctime>
#include <cstdlib>
#include "Manager.h"
#include "Run.h"

Manager::Manager(){
    srand(time(NULL));
    Welcome welcome;
    system("cls");
    Run run(welcome.getLineLength(), welcome.getLineSpeed(), welcome.getLineFrequency(), welcome.isEpilepsyMode());
}
