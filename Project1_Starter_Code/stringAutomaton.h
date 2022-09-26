//
// Created by stewj on 9/24/2022.
//

#ifndef PROJECT1_STARTER_CODE_STRINGAUTOMATON_H
#define PROJECT1_STARTER_CODE_STRINGAUTOMATON_H
#include "Automaton.h"

class stringAutomaton : public Automaton{
public:
    stringAutomaton() : Automaton(TokenType::STRING) {};
    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);

};


#endif //PROJECT1_STARTER_CODE_STRINGAUTOMATON_H
