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
    Run run(welcome.getLineLength(), welcome.getLineSpeed(), welcome.getLineFrequency(), welcome.isEpilepsyMode(), welcome.getExplosionProbability(), welcome.getMinimalRadius(), welcome.getMaximalRadius());

}

//#include <iostream>
//#include <cmath>
//#include "Manager.h"
//#include "Run.h"
//
//Manager::Manager(){
//    Windows windows;
//    double centerX = 55;
//    double centerY = 15;
//    windows.GotoXY(centerX, centerY);
//    printf("o");
//
//    double radius = 5;
//    double thickness = 0.5;
//    char symbol = '*';
//    double rIn = radius - thickness;
//    double rOut = radius + thickness;
//
//    for (int y = centerY + radius; y >= centerY - radius; --y)
//    {
//        for (int x = centerX - radius; x < centerX + rOut; ++x)
//        {
//            double distanceFromCenter = sqrt(pow(x - centerX, 2) + pow(y - centerY, 2));
//            if (distanceFromCenter >= rIn && distanceFromCenter <= rOut)
//            {
//                windows.GotoXY(x, y);
//                std::cout << symbol;
//            }
//        }
//        std::cout << std::endl;
//    }
//    windows.GotoXY(radius*2,radius);
//    printf("o");
//}