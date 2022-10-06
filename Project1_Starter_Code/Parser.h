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

private:
};


#endif //MAIN_CPP_PARSER_H
