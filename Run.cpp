//
// Created by AnnyB on 25.10.2023.
//

#include <synchapi.h>
#include <chrono>
#include "Run.h"
#include "Line.h"

void Run::Start() {

    int time_points[LineFrequency];
    const auto start{std::chrono::steady_clock::now()};
    auto end{std::chrono::steady_clock::now()};

    for (int i = 0; i < LineFrequency; i++){
        time_points[i] = 1 + rand()%999;
    }

    for (auto iter = lines.begin(); iter != lines.end();) {
        iter->Move();
        if(iter->EOL){
            lines.erase(iter);
        } else iter++;

        Sleep(1000/LineSpeed);
    }

//    while (true){
//        for (int i = 0; i < LineFrequency; i++){
//            time_points[i] = 1 + rand()%999;
//            lines.push_back(*new Line(LineLength, EpilepsyMode));
//        }
//        const std::chrono::duration<double> elapsed_seconds{end - start};
//        while (true){
//
//            if(elapsed_seconds.count() == 1000){
//                break;
//            }
//
//        }
//        end = {std::chrono::steady_clock::now()};
//    }
}

Run::Run(int lineLength, int lineSpeed, int lineFrequency, bool epilepsyMode) : LineLength(lineLength),
                                                                                LineSpeed(lineSpeed),
                                                                                LineFrequency(lineFrequency),
                                                                                EpilepsyMode(epilepsyMode) {
//    Line line = *new Line(LineLength, EpilepsyMode);
//    const auto start{std::chrono::steady_clock::now()};
//    auto end{std::chrono::steady_clock::now()};
    while (true){
        const auto start{std::chrono::steady_clock::now()};
//        for (int i = 0; i < LineFrequency; i++){
//            lines.push_back(*new Line(LineLength, EpilepsyMode));
//        }
        lines.push_back(*new Line(LineLength, EpilepsyMode));
        Start();
        auto end{std::chrono::steady_clock::now()};
        const std::chrono::duration<double> elapsed_seconds{end - start};

        Sleep(1000/LineFrequency);
    }

//    for(int i = 0; i < 100; i++){
//        line.Move();
//        if (line.EOL) {
//            break;
//        }
//        Sleep(1000/LineSpeed);
//    }

}
