//
// Created by stewj on 9/24/2022.
//

#ifndef PROJECT1_STARTER_CODE_UNDEFINEDAUTOMATON_H
#define PROJECT1_STARTER_CODE_UNDEFINEDAUTOMATON_H

#include "Automaton.h"
class undefinedAutomaton : public Automaton{
public:
    undefinedAutomaton() : Automaton(TokenType::UNDEFINED) {};
    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);

};


#endif //PROJECT1_STARTER_CODE_UNDEFINEDAUTOMATON_H
