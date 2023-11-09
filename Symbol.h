//
// Created by AnnyB on 25.10.2023.
//

#ifndef MATRIX_SYMBOL_H
#define MATRIX_SYMBOL_H


class Symbol {
    bool EpilepsyMode;
public:
    explicit Symbol(bool epilepsyMode);
    static void SetColor(int text);
    static void SetTextColor();
    char SetValue() const;

    ~Symbol();
};


#endif //MATRIX_SYMBOL_H
