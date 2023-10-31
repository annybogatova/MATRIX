//
// Created by AnnyB on 25.10.2023.
//

#ifndef MATRIX_RUN_H
#define MATRIX_RUN_H


class Run {
    int LineLength;
    int LineSpeed;
    int LineFrequency;
    bool EpilepsyMode;

public:
    Run(int lineLength, int lineSpeed, int lineFrequency, bool epilepsyMode);
};


#endif //MATRIX_RUN_H
