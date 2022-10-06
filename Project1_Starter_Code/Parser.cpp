//
// Created by john stewart on 10/5/22.
//

#include "Parser.h"
#include <vector>

DatalogProgram* Parser::Parse(std::vector<Token*> tokens){
    try {
        DatalogProgram *program = new DatalogProgram;
        if (tokens[0]->type == TokenType::SCHEMES) {
            tokens.erase(tokens.begin());
        } else {
            throw(tokens[0]);
        }
        if (tokens[0]->type == TokenType::COLON){
            tokens.erase(tokens.begin());
        }
        else{
            throw(tokens[0]);
        }




    return program;
    } catch (Token error){
        exit(0);
    }
}

void Parser::Schemes(std::vector<Token*> tokens, DatalogProgram* program){

}
