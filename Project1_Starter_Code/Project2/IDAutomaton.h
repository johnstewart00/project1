//
// Created by stewj on 9/23/2022.
//

#ifndef PROJECT1_STARTER_CODE_IDAUTOMATON_H
#define PROJECT1_STARTER_CODE_IDAUTOMATON_H

#include "Automaton.h"
class IDAutomaton : public Automaton {
public:
    IDAutomaton() : Automaton(TokenType::ID) {}  // Call the base constructor
    void S0(const std::string& input);
    void S1(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_IDAUTOMATON_H
