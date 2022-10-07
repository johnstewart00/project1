//
// Created by john stewart on 10/5/22.
//

#include "Parser.h"
#include <string>
#include <vector>

DatalogProgram* Parser::Parse(std::vector<Token*> tokens){
    try {
        DatalogProgram *program = new DatalogProgram;
        Schemes(tokens, program);
        Facts(tokens, program);
        Rules(tokens, program);
    return program;
    } catch (Token error){
        exit(0);
    }
}

void Parser::Schemes(std::vector<Token*> tokens, DatalogProgram* program){
    try {
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
    if(tokens[0]->type == TokenType::ID){
        AddPredicate(tokens, program, "schemes", TokenType::FACTS);
        return;
    }
    else {
        throw(tokens[0]);
    }
    } catch (Token error){
        exit(0);
    }
}

void Parser::AddPredicate(std::vector<Token*> tokens, DatalogProgram* program, std::string predicateType, TokenType next){
    try {
        Predicate* newPredicate = new Predicate;
        newPredicate->setID(tokens[0]->getDescription());
        program->push_back(newPredicate, predicateType);
        tokens.erase(tokens.begin());
        if(tokens[0]->type == TokenType::LEFT_PAREN) {
            tokens.erase(tokens.begin());
            if(predicateType == "schemes") {
                AddSchemesParameter(tokens, program, newPredicate);
            }
            else if(predicateType == "facts"){
                AddFactsParameter(tokens, program, newPredicate);
            }
            if(tokens[0]->type == TokenType::ID){
                AddPredicate(tokens, program, predicateType, next);
            }
            else if(tokens[0]->type == next){
                return;
            }
            else {
                throw(tokens[0]);
            }
        }
        else {
            throw (tokens[0]);
        }

    } catch(Token Error){
        exit(0);
    }
    return;
}

void Parser::AddSchemesParameter(std::vector<Token*> tokens, DatalogProgram* program, Predicate* newPredicate){
    try {
        if (tokens[0]->type == TokenType::ID) {
            Parameter *newParameter = new Parameter;
            newParameter->setContent(tokens[0]->getDescription());
            newPredicate->addParameter(newParameter);
            tokens.erase(tokens.begin());
            if (tokens[0]->type == TokenType::COMMA) {
                tokens.erase(tokens.begin());
                AddSchemesParameter(tokens, program, newPredicate);
            } else if (tokens[0]->type == TokenType::RIGHT_PAREN) {
                tokens.erase(tokens.begin());
                return;
            } else {
                throw (tokens[0]);
            }
        } else {
            throw (tokens[0]);
        }
    } catch(Token Error){
        exit(0);
    }

}

void Parser::AddFactsParameter(std::vector<Token*> tokens, DatalogProgram* program, Predicate* newPredicate){
    try {
        if (tokens[0]->type == TokenType::STRING) {
            Parameter *newParameter = new Parameter;
            newParameter->setContent(tokens[0]->getDescription());
            newPredicate->addParameter(newParameter);
            tokens.erase(tokens.begin());
            if (tokens[0]->type == TokenType::COMMA) {
                tokens.erase(tokens.begin());
                AddFactsParameter(tokens, program, newPredicate);
            } else if (tokens[0]->type == TokenType::RIGHT_PAREN) {
                tokens.erase(tokens.begin());
                return;
            } else {
                throw (tokens[0]);
            }
        } else {
            throw (tokens[0]);
        }
    } catch(Token Error){
        exit(0);
    }
}


void Parser::Facts(std::vector<Token*> tokens, DatalogProgram* program){
    try {
        if (tokens[0]->type == TokenType::FACTS) {
            tokens.erase(tokens.begin());
            if(tokens[0]->type == TokenType::COLON){
                tokens.erase(tokens.begin());
                if(tokens[0]->type == TokenType::ID){
                    AddPredicate(tokens, program, "facts", TokenType::RULES);
                    return;
                }
                else {
                    throw(tokens[0]);
                }
            }
            else {
                throw(tokens[0]);
            }
        } else {
            throw (tokens[0]);
        }

    } catch (Token Error){
        exit(0);
    }
}

void Parser::Rules(std::vector<Token*> tokens, DatalogProgram* program){
    try{
        if(tokens[0]->type == TokenType::RULES){
            tokens.erase(tokens.begin());
            if(tokens[0]->type == TokenType::COLON){
                addHeadPredicate(tokens, program);
            }
            else {
                throw tokens[0];
            }
        }
        else {
            throw(tokens[0]);
        }
    } catch(Token Error){
        exit(0);
    }
}

void Parser::addHeadPredicate(std::vector<Token*>tokens, DatalogProgram* program){

}

