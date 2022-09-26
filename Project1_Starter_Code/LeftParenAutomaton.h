//
// Created by stewj on 9/20/2022.
//

#ifndef PROJECT1_STARTER_CODE_LEFTPARENAUTOMATON_H
#define PROJECT1_STARTER_CODE_LEFTPARENAUTOMATON_H
#include "Automaton.h"

class LeftParenAutomaton : public Automaton {
public:
    LeftParenAutomaton() : Automaton(TokenType::LEFT_PAREN) {};
    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_LEFTPARENAUTOMATON_H
