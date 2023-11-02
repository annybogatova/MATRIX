//
// Created by AnnyB on 25.10.2023.
//

#ifndef MATRIX_RUN_H
#define MATRIX_RUN_H


#include <vector>
#include "Line.h"

class Run {
    int LineLength;
    int LineSpeed;
    int LineFrequency;
    bool EpilepsyMode;

    std::vector<Line> lines;

public:
    Run(int lineLength, int lineSpeed, int lineFrequency, bool epilepsyMode);
    void Start();
    int time_points[];
};


#endif //MATRIX_RUN_H
