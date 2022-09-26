//
// Created by stewj on 9/20/2022.
//

#ifndef PROJECT1_STARTER_CODE_RIGHTPAREN_H
#define PROJECT1_STARTER_CODE_RIGHTPAREN_H
#include "Automaton.h"

class RightParen : public Automaton {
public:
    RightParen() : Automaton(TokenType::RIGHT_PAREN) {};
    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_RIGHTPAREN_H
