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
    const char *em_mess = "Epilepsy mode Y/N (on/off)\n";

    int LineLength;
    int LineSpeed;
    int LineFrequency;
    bool EpilepsyMode;

    void IntroduceSelf();
    void CheckParameters();
public:
    int getLineLength() const;

    void setLineLength();

    int getLineSpeed() const;

    void setLineSpeed();

    int getLineFrequency() const;

    void setLineFrequency();

    bool isEpilepsyMode() const;

    void setEpilepsyMode();

    Welcome();

};


#endif //MATRIX_WELCOME_H
