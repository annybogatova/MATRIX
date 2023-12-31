//
// Created by AnnyB on 25.10.2023.
//

#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <synchapi.h>
#include "Welcome.h"
#include "Manager.h"
#include "Run.h"
#include "Line.h"

Welcome::Welcome() {
    IntroduceSelf();
}

void Welcome::IntroduceSelf() {
    printf("%s", this->welcome_mess);
    CheckParameters();
}


void Welcome::setLineLength() {
    printf("%s", this->ll_mess);
    char line[256];
    int length;
    while (true){
        scanf("%d", &length);
        if (length >= 1 && length <= 30){
            break;
        }
        printf("Wrong input!\n");
    }
    LineLength = length;
}


void Welcome::setLineSpeed() {
    printf("%s", this->ls_mess);
    int speed;
    while (true){
        scanf("%d", &speed);
        if (speed >= 1 && speed <= 30){
            break;
        }
        printf("Wrong input!\n");
    }
    LineSpeed = speed;
}

void Welcome::setLineFrequency() {
    printf("%s", this->lf_mess);
    char line[10];
    int frequency = 0;
    while (true){
        scanf("%s", line);
        if(isdigit(line[0])){
            frequency = atoi(line);
            if (frequency >= 1 && frequency <= 30){
                break;
            }
        }
        printf("Wrong input!\n");
    }
    LineFrequency = frequency;
}

void Welcome::setEpilepsyMode() {
    printf("%s", this->em_mess);
    bool epilepsy = false;
    char mode;
    while (true){
        scanf("%s", &mode);
        if ((char) mode == 'Y' || (char) mode == 'y'){
            epilepsy = true;
            break;
        } else if((char) mode == 'N' || (char) mode == 'n'){
            epilepsy = false;
            break;
        }
        printf("Wrong input!\n");
    }
    EpilepsyMode = epilepsy;
}

void Welcome::CheckParameters() {
    setLineFrequency();
    setLineSpeed();
    setLineLength();
    setEpilepsyMode();
}


bool Welcome::isEpilepsyMode() const {
    return EpilepsyMode;
}

int Welcome::getLineLength() const {
    return LineLength;
}

int Welcome::getLineSpeed() const {
    return LineSpeed;
}

int Welcome::getLineFrequency() const {
    return LineFrequency;
}