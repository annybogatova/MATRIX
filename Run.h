//
// Created by AnnyB on 25.10.2023.
//

#ifndef MATRIX_RUN_H
#define MATRIX_RUN_H


#include <chrono>
#include <vector>
#include "Line.h"
#include "Explosion.h"

class Run {
    int LineLength = 0;
    int LineSpeed = 0;
    int LineFrequency = 0;
    int ExplosionProbability = 0;
    int MinimalRadius = 0;
    int MaximalRadius = 0;
    bool EpilepsyMode = false;
//    std::vector<Line> lines;
//    std::vector<Explosion> explCircles;
    std::vector<Figure*> figures;
    std::vector<double> time_points;
    std::chrono::time_point<std::chrono::steady_clock> startClock, endClock;
    std::chrono::duration<double> elapsed_seconds;

public:
    Run(int lineLength, int lineSpeed, int lineFrequency, bool epilepsyMode, int explosionProbability, int minimalRadius, int maximalRadius);
    void Start();

    void SetRandTimePoints();

    double GetRandomDouble(double a, double b);
};


#endif //MATRIX_RUN_H
