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
        //std::cout << "in Parse function" << std::endl;
        DatalogProgram *program = new DatalogProgram;
        Schemes(tokens, program);
        Facts(tokens, program);
        Rules(tokens, program);
        Queries(tokens, program);
        //cout << "this program is almost done if it works" << endl;
    return program;
    } catch (Token* error){
        error->failure(error->toString(), error->getDescription(), error->getLine());
        exit(0);
    }
}

void Parser::Schemes(std::vector<Token*> &tokens, DatalogProgram* &program){
    try {
        //cout << "In Schemes function" << endl;
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
        error->failure(error->toString(), error->getDescription(), error->getLine());
    }
}

void Parser::AddPredicate(std::vector<Token*> &tokens, DatalogProgram* &program, std::string predicateType, TokenType next){
    try {
        //cout << "In addPredicate the current token type  and desc is: " << tokens[0]->toString() << ' ' << tokens[0]->getDescription() <<  endl;
        Predicate* newPredicate = new Predicate;
        newPredicate->setID(tokens[0]->getDescription());
        tokens.erase(tokens.begin());
        if(tokens[0]->type == TokenType::LEFT_PAREN) {
            tokens.erase(tokens.begin());
            if(predicateType == "schemes") {
                AddSchemesParameter(tokens, program, newPredicate);
            }
            else if(predicateType == "facts"){
                AddFactsParameter(tokens, program, newPredicate);
            }
            else if(predicateType == "queries"){
                AddQueryParameter(tokens, program, newPredicate);
            }
            if(tokens[0]->type == TokenType::ID){
                program->push_back(newPredicate, predicateType);
                AddPredicate(tokens, program, predicateType, next);
            }
            else if(tokens[0]->type == next){
                program->push_back(newPredicate, predicateType);
                return;
            }
            else {
                //cout << __LINE__ << endl;
                throw(tokens[0]);
            }
        }
        else {
            cout << __LINE__ << endl;
            throw (tokens[0]);
        }

    } catch(Token* error){
        error->failure(error->toString(), error->getDescription(), error->getLine());

    }
    return;
}

void Parser::AddSchemesParameter(std::vector<Token*> &tokens, DatalogProgram* &program, Predicate* &newPredicate){
    try {
        //cout << "in AddSchemes Parameter" << endl;
        if (tokens[0]->type == TokenType::ID) {
            Parameter *newParameter = new Parameter;
            newParameter->setContent(tokens[0]->getDescription());
            newPredicate->addParameter(newParameter);
            //program->push_back(newPredicate, "schemes"); // added code
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
    } catch(Token* error){
        error->failure(error->toString(), error->getDescription(), error->getLine());
    }

}

void Parser::AddFactsParameter(std::vector<Token*> &tokens, DatalogProgram* &program, Predicate* &newPredicate){
    try {
        //cout << "In addFactsParameter with: " << tokens[0]->getDescription() << endl;
        if (tokens[0]->type == TokenType::STRING) {
            Parameter *newParameter = new Parameter;
            newParameter->setContent(tokens[0]->getDescription());
            newPredicate->addParameter(newParameter);
            program->insertDomain(newParameter->returnContent());
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
    } catch(Token* error){
        error->failure(error->toString(), error->getDescription(), error->getLine());
    }
}


void Parser::Facts(std::vector<Token*> &tokens, DatalogProgram* &program){
    try {
        //cout << "Made it to Facts with token[0]: " << tokens[0]->getDescription() << endl;
        if (tokens[0]->type == TokenType::FACTS) {
            tokens.erase(tokens.begin());
            if(tokens[0]->type == TokenType::COLON){
                tokens.erase(tokens.begin());
                if(tokens[0]->type == TokenType::ID){
                    AddPredicate(tokens, program, "facts", TokenType::RULES);
                    return;
                } else if(tokens[0]->type == TokenType::RULES){
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

    } catch (Token* error){
        error->failure(error->toString(), error->getDescription(), error->getLine());
    }
}

void Parser::Rules(std::vector<Token*> &tokens, DatalogProgram* &program){
    try{
        //cout << "Made it to Rules with token[0]: " << tokens[0]->getDescription() << endl;
        if(tokens[0]->type == TokenType::RULES){
            tokens.erase(tokens.begin());
            if(tokens[0]->type == TokenType::COLON){
                tokens.erase(tokens.begin());
                createNewRule(tokens, program);
                //cout << "created all rules" << endl;
                return;
            }
            else {
                throw tokens[0];
            }
        }
        else {
            throw(tokens[0]);
        }
    } catch(Token* error){
        error->failure(error->toString(), error->getDescription(), error->getLine());
    }
}
void Parser::createNewRule(std::vector<Token*> &tokens, DatalogProgram* &program){
    try {
        if(tokens[0]->type == TokenType::QUERIES){
            return;
        }
        Predicate *head = addHeadPredicate(tokens, program);
        Rule *newRule = new Rule;
        newRule->sethead(head);
        if (tokens[0]->type == TokenType::COLON_DASH) {
            tokens.erase(tokens.begin());
            vector<Predicate *> body = createRuleBody(tokens, program);
            newRule->setbody(body);
            program->addRule(newRule);
            if(tokens[0]->type == TokenType::QUERIES){
                return;
            } else if(tokens[0]->type == TokenType::ID){
                createNewRule(tokens, program);
            } else{
                throw(tokens[0]);
            }
        } else {
            throw (tokens[0]);
        }
    } catch (Token* error){
        error->failure(error->toString(), error->getDescription(), error->getLine());
    }
}


Predicate* Parser::addHeadPredicate(std::vector<Token*> &tokens, DatalogProgram* &program){
    //cout << "Creating a Head Predicate for Rules for: " << tokens[0]->getDescription() << endl;
    try{
        //cout << "In addHeadPredicate with tokens[0]: " << tokens[0]->getDescription();
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
    } catch (Token* error){
        error->failure(error->toString(), error->getDescription(), error->getLine());
        exit(0);
    }
}
void Parser::addPredicateHeadParameter(std::vector<Token*> &tokens, DatalogProgram* &program, Predicate* &head){
    //cout << "adding head parameters for head predicate in Rules for: " << tokens[0]->getDescription() << endl;
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
    } catch(Token* error){
        error->failure(error->toString(), error->getDescription(), error->getLine());
    }
}

vector<Predicate*> Parser::createRuleBody(std::vector<Token*> &tokens, DatalogProgram* &program) {
    //cout << "creating rules body" << endl;
    vector<Predicate *> vectorOfPredicates;
    createPredicates(tokens, program, vectorOfPredicates);
    return vectorOfPredicates;
}


void Parser::createPredicates(std::vector<Token*> &tokens, DatalogProgram* &program, vector<Predicate*> &body){\
//cout << "creating rule body predicates" << endl;
    try {
        //cout << "in createRuleBody with tokens[0]: " << tokens[0]->getDescription() << endl;

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
    } catch (Token* error){
        error->failure(error->toString(), error->getDescription(), error->getLine());
    }
}

void Parser::addPredicateBodyParameter(std::vector<Token*> &tokens, DatalogProgram* &program, Predicate* &pred){
    //cout << "creating rule body predicate parameters" << endl;
    //cout << "in addPredicateBodyParameter with tokens[0]: " << tokens[0]->getDescription() << endl;
    try {
        if (tokens[0]->type == TokenType::ID or tokens[0]->type == TokenType::STRING) {
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
    } catch(Token* error){
        error->failure(error->toString(), error->getDescription(), error->getLine());
    }
}

void Parser::Queries (std::vector<Token*> &tokens, DatalogProgram* &program) {
    try{
        //cout << "Made it to Queries with token[0]: " << tokens[0]->getDescription() << endl;
        if(tokens[0]->type == TokenType::QUERIES){
            tokens.erase(tokens.begin());
            if(tokens[0]->type == TokenType::COLON){
                tokens.erase(tokens.begin());
                createQuery(tokens, program);
                return;
            }
            else {
                throw tokens[0];
            }
        }
        else {
            throw(tokens[0]);
        }
    } catch(Token* error){
        error->failure(error->toString(), error->getDescription(), error->getLine());
    }
}

void Parser::createQuery(std::vector<Token*> &tokens, DatalogProgram* &program){
    try {
//        if (tokens[0]->type == TokenType::ID) {
//            tokens.erase(tokens.begin());
//            if(tokens[0]->type == TokenType::LEFT_PAREN){
//                tokens.erase(tokens.begin());
                AddPredicate(tokens, program, "queries", TokenType::EOF_TYPE);
                //cout << "we should have gotten all the queries now" << endl;
                return;
//            } else {
//                throw (tokens[0]);
//            }
//        } else {
//            throw (tokens[0]);
//        }
    } catch(Token* error){
        error->failure(error->toString(), error->getDescription(), error->getLine());
    }
}
void Parser::AddQueryParameter(std::vector<Token*> &tokens, DatalogProgram* &program, Predicate* &newPredicate){
    try {
        //cout << "in AddQuery Parameter" << endl;
        if (tokens[0]->type == TokenType::ID or tokens[0]->type == TokenType::STRING) {
            Parameter *newParameter = new Parameter;
            newParameter->setContent(tokens[0]->getDescription());
            newPredicate->addParameter(newParameter);
            tokens.erase(tokens.begin());
            if (tokens[0]->type == TokenType::COMMA) {
                tokens.erase(tokens.begin());
                AddQueryParameter(tokens, program, newPredicate);
            } else if (tokens[0]->type == TokenType::RIGHT_PAREN) {
                tokens.erase(tokens.begin());
                if(tokens[0]->type == TokenType::Q_MARK){
                    tokens.erase(tokens.begin());
                } else {
                    throw (tokens[0]);
                }
                return;
            } else {
                throw (tokens[0]);
            }
        } else {
            throw (tokens[0]);
        }
    } catch(Token* error){
        error->failure(error->toString(), error->getDescription(), error->getLine());
    }
}



