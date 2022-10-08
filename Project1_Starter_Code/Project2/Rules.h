//
// Created by stewj on 9/20/2022.
//

#ifndef PROJECT1_STARTER_CODE_RULES_H
#define PROJECT1_STARTER_CODE_RULES_H
#include "Automaton.h"

class Rules : public Automaton{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
    void S5(const std::string& input);
public:
    Rules() : Automaton(TokenType::RULES) {};
    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_RULES_H
