//
// Created by stewj on 9/20/2022.
//

#ifndef PROJECT1_STARTER_CODE_Q_MARKAUTOMATON_H
#define PROJECT1_STARTER_CODE_Q_MARKAUTOMATON_H

#include "Automaton.h"

class Q_MarkAutomaton : public Automaton {
public:
    Q_MarkAutomaton() : Automaton(TokenType::Q_MARK) {}  // Call the base constructor
    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_Q_MARKAUTOMATON_H
