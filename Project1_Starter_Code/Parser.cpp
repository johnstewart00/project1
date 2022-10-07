//
// Created by john stewart on 10/5/22.
//

#include "Parser.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;


DatalogProgram* Parser::Parse(std::vector<Token*> tokens){
    try {
        std::cout << "in Parse function" << std::endl;
        DatalogProgram *program = new DatalogProgram;
        Schemes(tokens, program);
        Facts(tokens, program);
        Rules(tokens, program);
    return program;
    } catch (Token* error){
        cout << "What was caught was: " << error->toString() << endl;

        exit(0);
    }
}

void Parser::Schemes(std::vector<Token*> &tokens, DatalogProgram* &program){
    try {
        cout << "In Schemes function" << endl;
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
    } catch (Token* error){
        cout << "What was caught was: " << error->toString() << endl;
        exit(0);
    }
}

void Parser::AddPredicate(std::vector<Token*> &tokens, DatalogProgram* &program, std::string predicateType, TokenType next){
    try {
        cout << "In addPredicate the current token type is: " << tokens[0]->toString() << endl;
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
                cout << __LINE__ << endl;
                throw(tokens[0]);
            }
        }
        else {
            cout << __LINE__ << endl;
            throw (tokens[0]);
        }

    } catch(Token* Error){
        cout << "What was caught was: " << Error->toString() << endl;
        exit(0);
    }
    return;
}

void Parser::AddSchemesParameter(std::vector<Token*> &tokens, DatalogProgram* &program, Predicate* &newPredicate){
    try {
        cout << "in AddSchemes Parameter" << endl;
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
    } catch(Token* Error){
        cout << "What was caught was: " << Error->toString() << endl;

        exit(0);
    }

}

void Parser::AddFactsParameter(std::vector<Token*> &tokens, DatalogProgram* &program, Predicate* &newPredicate){
    try {
        cout << "In addFactsParameter with: " << tokens[0]->getDescription() << endl;
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
                if(tokens[0]->type == TokenType::PERIOD) {
                    tokens.erase(tokens.begin());
                    return;
                }
                else {
                    throw(tokens[0]);
                }
            } else {
                throw (tokens[0]);
            }
        } else {
            throw (tokens[0]);
        }
    } catch(Token* Error){
        cout << "What was caught was: " << Error->toString() << endl;

        exit(0);
    }
}


void Parser::Facts(std::vector<Token*> &tokens, DatalogProgram* &program){
    try {
        cout << "Made it to Facts with token[0]: " << tokens[0]->getDescription() << endl;
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

    } catch (Token* Error){
        cout << "What was caught was: " << Error->toString() << endl;

        exit(0);
    }
}

void Parser::Rules(std::vector<Token*> &tokens, DatalogProgram* &program){
    try{
        cout << "Made it to Rules with token[0]: " << tokens[0]->getDescription() << endl;
        if(tokens[0]->type == TokenType::RULES){
            tokens.erase(tokens.begin());
            if(tokens[0]->type == TokenType::COLON){
                tokens.erase(tokens.begin());
                Predicate* head = addHeadPredicate(tokens, program);
                Rule* newRule = new Rule;
                newRule->sethead(head);
                if(tokens[0]->type == TokenType::COLON_DASH){
                    tokens.erase(tokens.begin());
                    vector<Predicate*> body = createRuleBody(tokens, program);
                    newRule->setbody(body);
                } else {
                    throw(tokens[0]);
                }
            }
            else {
                throw tokens[0];
            }
        }
        else {
            throw(tokens[0]);
        }
    } catch(Token Error){
        cout << "What was caught was: " << Error.toString() << endl;
        exit(0);
    }
}

Predicate* Parser::addHeadPredicate(std::vector<Token*> &tokens, DatalogProgram* &program){
    cout << "Creating a Head Predicate for Rules for: " << tokens[0]->getDescription() << endl;
    try{
        cout << "In addHeadPredicate with tokens[0]: " << tokens[0]->getDescription();
        if(tokens[0]->type == TokenType::ID) {
            Predicate *head = new Predicate;
            head->setID(tokens[0]->getDescription());
            tokens.erase(tokens.begin());
            if (tokens[0]->type == TokenType::LEFT_PAREN){
                tokens.erase(tokens.begin());
                addPredicateHeadParameter(tokens, program, head);
                return head;
            } else {
                throw(tokens[0]);
            }
        }else {
            throw(tokens[0]);
        }
    } catch (Token Error){
        cout << "What was caught was: " << Error.toString() << endl;
        exit(0);
    }
}
void Parser::addPredicateHeadParameter(std::vector<Token*> &tokens, DatalogProgram* &program, Predicate* &head){
    cout << "adding head parameters for head predicate in Rules for: " << tokens[0]->getDescription() << endl;
    try {
        if (tokens[0]->type == TokenType::ID) {
            Parameter *newparameter = new Parameter;
            newparameter->setContent(tokens[0]->getDescription());
            head->addParameter(newparameter);
            tokens.erase(tokens.begin());
            if(tokens[0]->type == TokenType::COMMA){
                tokens.erase(tokens.begin());
                addPredicateHeadParameter(tokens, program, head);
            }
            else if (tokens[0]->type == TokenType::RIGHT_PAREN){
                tokens.erase(tokens.begin());
                return;
            }
            else {
                throw(tokens[0]);
            }
        } else {
            throw (tokens[0]);
        }
    } catch(Token Error){
        cout << "What was caught was: " << Error.toString() << endl;
        exit(0);
    }
}

vector<Predicate*> Parser::createRuleBody(std::vector<Token*> &tokens, DatalogProgram* &program) {
    cout << "creating rules body" << endl;
    vector<Predicate *> vectorOfPredicates;
    if(tokens[0]->type == TokenType::ID){
        createPredicates(tokens, program, vectorOfPredicates);
    }
    return vectorOfPredicates;
}

//void Parser::wrapper make wrapper function to recusrively call createPredicates instead of calling it from CreateRule Body

void Parser::createPredicates(std::vector<Token*> &tokens, DatalogProgram* &program, vector<Predicate*> &body){\
cout << "creating rule body predicates" << endl;
    try {
        cout << "in createRuleBody with tokens[0]: " << tokens[0]->getDescription() << endl;

        if (tokens[0]->type == TokenType::ID) {
            Predicate *pred = new Predicate;
            pred->setID(tokens[0]->getDescription());
            tokens.erase(tokens.begin());
            if (tokens[0]->type == TokenType::LEFT_PAREN){
                tokens.erase(tokens.begin());
                addPredicateBodyParameter(tokens, program, pred);
                body.push_back(pred);
                if(tokens[0]->type == TokenType::COMMA){
                    tokens.erase(tokens.begin());
                    createPredicates(tokens, program, body);
                } else {
                    if(tokens[0]->type == TokenType::PERIOD){
                        tokens.erase(tokens.begin());
                        return;
                    }
                }
            } else {
                throw(tokens[0]);
            }
        }else {
            throw(tokens[0]);
        }
    } catch (Token Error){
        cout << "What was caught was: " << Error.toString() << endl;
        exit(0);
    }
}

void Parser::addPredicateBodyParameter(std::vector<Token*> &tokens, DatalogProgram* &program, Predicate* &pred){
    cout << "creating rule body predicate parameters" << endl;
    cout << "in addPredicateBodyParameter with tokens[0]: " << tokens[0]->getDescription() << endl;
    try {
        if (tokens[0]->type == TokenType::ID) {
            Parameter *newparameter = new Parameter;
            newparameter->setContent(tokens[0]->getDescription());
            pred->addParameter(newparameter);
            tokens.erase(tokens.begin());
            if(tokens[0]->type == TokenType::COMMA){
                tokens.erase(tokens.begin());
                addPredicateBodyParameter(tokens, program, pred);
            }
            else if (tokens[0]->type == TokenType::RIGHT_PAREN){
                tokens.erase(tokens.begin());
                return;
            }
            else {
                throw(tokens[0]);
            }
        } else {
            throw (tokens[0]);
        }
    } catch(Token Error){
        cout << "What was caught was: " << Error.toString() << endl;
        exit(0);
    }
}