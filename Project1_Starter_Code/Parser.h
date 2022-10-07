//
// Created by john stewart on 10/5/22.
//

#ifndef MAIN_CPP_PARSER_H
#define MAIN_CPP_PARSER_H
#include "Token.h"
#include "DatalogProgram.h"
#include <string>
#include <vector>
using namespace std;

class Parser {
public:
    Parser() {};
    void Schemes(vector<Token*> tokens, DatalogProgram* program);
    DatalogProgram* Parse(vector<Token*> tokens);
    void AddPredicate(std::vector<Token*> tokens, DatalogProgram* program, std::string predicateType, TokenType next);
    void AddSchemesParameter(std::vector<Token*> tokens, DatalogProgram* program, Predicate* newPredicate);
    void AddFactsParameter(std::vector<Token*> tokens, DatalogProgram* program, Predicate* newPredicate);
    void Rules(std::vector<Token*> tokens, DatalogProgram* program);
    void Facts(std::vector<Token*> tokens, DatalogProgram* program);

private:


    };


#endif //MAIN_CPP_PARSER_H
