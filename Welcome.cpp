//
// Created by AnnyB on 25.10.2023.
//

#include <cstdio>
#include <ctime>
#include <cstdlib>
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
    while (true){
        try{
            printf("%s", this->ll_mess);
            if(scanf("%d", &LineLength) != 1){
                while (fgetc(stdin) != '\n');
                throw std::invalid_argument("Entered value must be integer.\n");
            }
            if(LineLength < 1 || LineLength > 30){
                throw std::out_of_range("Enter value in range [1-30]\n");
            }
            break;
        }
        catch (const std::invalid_argument &err){
            fprintf(stderr, "%s", err.what());
        }
        catch (const std::out_of_range &err){
            fprintf(stderr, "%s", err.what());
        }
    }
}

void Welcome::setLineSpeed() {
    while (true){
        try{
            printf("%s", this->ls_mess);
            if(scanf("%d", &LineSpeed) != 1){
                while (fgetc(stdin) != '\n');
                throw std::invalid_argument(this->int_err);
            }
            if(LineSpeed < 1 || LineSpeed > 30){
                throw std::out_of_range("Enter value in range [1-30]\n");
            }
            break;
        }
        catch (const std::invalid_argument &err){
            fprintf(stderr, "%s", err.what());
        }
        catch (const std::out_of_range &err){
            fprintf(stderr, "%s", err.what());
        }
    }
}

void Welcome::setLineFrequency() {
    while (true){
        try{
            printf("%s", this->lf_mess);
            if(scanf("%d", &LineFrequency) != 1){
                while (fgetc(stdin) != '\n');
                throw std::invalid_argument(this->int_err);
            }
            if(LineFrequency < 1 || LineFrequency > 30){
                throw std::out_of_range("Enter value in range [1-30]\n");
            }
            break;
        }
        catch (const std::invalid_argument &err){
            fprintf(stderr, "%s", err.what());
        }
        catch (const std::out_of_range &err){
            fprintf(stderr, "%s", err.what());
        }
    }
}
void Welcome::setExplosionProbability() {
    while (true){
        try{
            printf("%s", this->ple_mess);
            if(scanf("%d", &ExplosionProbability) != 1){
                while (fgetc(stdin) != '\n');
                throw std::invalid_argument(this->int_err);
            }
            if(ExplosionProbability < 1 || ExplosionProbability > 1000){
                throw std::out_of_range("Enter value in range [1-1000]\n");
            }
            break;
        }
        catch (const std::invalid_argument &err){
            fprintf(stderr, "%s", err.what());
        }
        catch (const std::out_of_range &err){
            fprintf(stderr, "%s", err.what());
        }
    }
}

void Welcome::setMinimalRadius() {
    while (true){
        try{
            printf("%s", this->miner_mess);
            if(scanf("%d", &MinimalRadius) != 1){
                while (fgetc(stdin) != '\n');
                throw std::invalid_argument(this->int_err);
            }
            if(MinimalRadius < 1 || MinimalRadius > 30){
                throw std::out_of_range("Enter value in range [1-10]\n");
            }
            break;
        }
        catch (const std::invalid_argument &err){
            fprintf(stderr, "%s", err.what());
        }
        catch (const std::out_of_range &err){
            fprintf(stderr, "%s", err.what());
        }
    }
}

void Welcome::setMaximalRadius() {
    while (true){
        try{
            printf("%s", this->maxer_mess);
            if(scanf("%d", &MaximalRadius) != 1){
                while (fgetc(stdin) != '\n');
                throw std::invalid_argument(this->int_err);
            }
            if(MaximalRadius < 1 || MaximalRadius > 10){
                throw std::out_of_range("Enter value in range [1-10]\n");
            }
            break;
        }
        catch (const std::invalid_argument &err){
            fprintf(stderr, "%s", err.what());
        }
        catch (const std::out_of_range &err){
            fprintf(stderr, "%s", err.what());
        }
    }
}

void Welcome::setEpilepsyMode() {
    printf("%s", this->em_mess);
    bool epilepsy = false;
    char mode;
    while (true){
        scanf("%s", &mode);
        try{
            if ((char) mode == 'Y' || (char) mode == 'y'){
                epilepsy = true;
                break;
            } else if((char) mode == 'N' || (char) mode == 'n'){
                epilepsy = false;
                break;
            } else throw std::invalid_argument("Enter Y or N\n");
        } catch (const std::invalid_argument &err){
            fprintf(stderr, "%s", err.what());
        }
    }
    EpilepsyMode = epilepsy;
}

void Welcome::CheckParameters() {
    setLineFrequency();
    setLineSpeed();
    setLineLength();
    setExplosionProbability();
    setMinimalRadius();
    setMaximalRadius();
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

int Welcome::getExplosionProbability() const {
    return ExplosionProbability;
}
int Welcome::getMinimalRadius() const {
    return MinimalRadius;
}
int Welcome::getMaximalRadius() const {
    return MaximalRadius;
}