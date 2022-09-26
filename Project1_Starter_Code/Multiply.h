//
// Created by stewj on 9/20/2022.
//

#ifndef PROJECT1_STARTER_CODE_MULTIPLY_H
#define PROJECT1_STARTER_CODE_MULTIPLY_H
#include "Automaton.h"

class Multiply : public Automaton{
public:
    Multiply() : Automaton(TokenType::MULTIPLY) {};
    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_MULTIPLY_H
