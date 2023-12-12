//
// Created by AnnyB on 25.10.2023.
//

#include <synchapi.h>
#include <chrono>
#include <vector>
#include <algorithm>
#include <random>

#include "Run.h"
#include "Line.h"

void Run::Start() {
    while (true){
        endClock = std::chrono::steady_clock::now();
        elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(endClock - startClock);
        if (!time_points.empty()){
            auto begin = time_points.begin();
            if (elapsed_seconds.count() >= *begin){
                time_points.erase(begin);
                figures.push_back(new Line(LineLength, LineSpeed, ExplosionProbability, EpilepsyMode));
            }
        }
        endClock = std::chrono::steady_clock::now();
        elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(endClock - startClock);
        if (elapsed_seconds.count() > 1){
            startClock = std::chrono::steady_clock::now();
            time_points.clear();
            SetRandTimePoints();
        }
        if (!figures.empty()){
            for (auto iter = figures.begin(); iter != figures.end();){
                if ((*iter)->EOL){
                    figures.erase(iter);
                } else{
                    (*iter)->TryMove();
                    if((*iter)->isExplod){
                        figures.push_back(new Explosion((*iter)->getCoordinates().first, (*iter)->getCoordinates().second,MinimalRadius, MaximalRadius));
                    }
                    ++iter;
                }
            }
        }
    }
}

Run::Run(int lineLength, int lineSpeed, int lineFrequency, bool epilepsyMode, int explosionProbability, int minimalRadius, int maximalRadius) : LineLength(lineLength),
                                                                                LineSpeed(lineSpeed),
                                                                                LineFrequency(lineFrequency),
                                                                                EpilepsyMode(epilepsyMode),
                                                                                ExplosionProbability(explosionProbability),
                                                                                MinimalRadius(minimalRadius),
                                                                                MaximalRadius(maximalRadius){
    Windows windows;
    SetRandTimePoints();
    figures.reserve(LineFrequency*LineSpeed*(windows.getConsoleSize().height)*ExplosionProbability);
    startClock = std::chrono::steady_clock::now();
    Start();
}

void Run::SetRandTimePoints(){
    for(size_t i = 0; i < LineFrequency; i ++){
        time_points.push_back(GetRandomDouble((double) 0, (double) 1));
    }
    std::sort(begin(time_points), end(time_points));
}

double Run::GetRandomDouble(double a, double b) {

    namespace sc = std::chrono;
    auto time = sc::system_clock::now(); // get the current time
    auto since_epoch = time.time_since_epoch(); // get the duration since epoch
    auto millis = sc::duration_cast<sc::nanoseconds>(since_epoch);

    std::random_device rd;
    std::mt19937 gen(millis.count());
    std::uniform_real_distribution<double> dis(a, b);

    double c = dis(gen);

    return c;
}

