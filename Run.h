//
// Created by AnnyB on 25.10.2023.
//

#ifndef MATRIX_RUN_H
#define MATRIX_RUN_H


#include <chrono>
#include <vector>
#include "Line.h"

class Run {
    int LineLength;
    int LineSpeed;
    int LineFrequency;
    bool EpilepsyMode;

    std::vector<Line> lines;
    std::vector<double> time_points;
    std::chrono::time_point<std::chrono::steady_clock> startClock, endClock;
    std::chrono::duration<double> elapsed_seconds;

public:
    Run(int lineLength, int lineSpeed, int lineFrequency, bool epilepsyMode);
    void Start();

    void SetRandTimePoints();

    double GetRandomDouble(double a, double b);
};


#endif //MATRIX_RUN_H
