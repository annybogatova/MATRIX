//
// Created by AnnyB on 25.10.2023.
//

#ifndef MATRIX_WELCOME_H
#define MATRIX_WELCOME_H


class Welcome {
    const char *welcome_mess = "Matrix: beginning\n";
    const char *lf_mess = "Enter line appearance frequency: 1 - 30 (lines per second)\n";
    const char *ls_mess = "Enter line speed 1 - 30 (characters per second)\n";
    const char *ll_mess = "Enter line length 1 - 30 (characters)\n";
    const char *ple_mess = "Enter probability of line explosion 1 - 1000\n";
    const char *miner_mess = "Enter minimum explosion radius 1 - 10 (characters)\n";
    const char *maxer_mess = "Enter maximum explosion radius 1 - 10 (characters, > minimum radius)\n";
    const char *em_mess = "Epilepsy mode Y/N (on/off)\n";
    const char *int_err = "Entered value must be integer.\n";
    const char *val_err = "Enter value in range ";

    int LineLength = 0;
    int LineSpeed = 0;
    int LineFrequency = 0;
    int ExplosionProbability = 0;
    int MinimalRadius = 0;
    int MaximalRadius = 0;
    bool EpilepsyMode = false;

    void IntroduceSelf();
    void CheckParameters();

public:
    void setLineLength();
    void setLineSpeed();
    void setLineFrequency();
    void setExplosionProbability();
    void setMaximalRadius();
    void setMinimalRadius();
    void setEpilepsyMode();

    int getLineLength() const;
    int getLineSpeed() const;
    int getLineFrequency() const;
    bool isEpilepsyMode() const;
    int getExplosionProbability() const;
    int getMinimalRadius() const;
    int getMaximalRadius() const;

    Welcome();
};


#endif //MATRIX_WELCOME_H
