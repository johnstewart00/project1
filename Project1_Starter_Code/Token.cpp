#include "Token.h"
#include <string>
#include <iostream>
using namespace std;

Token::Token(){
//    TokenType::UNDEFINED;
    description = "";
    line = 1;
}

Token::Token(TokenType type, std::string description, int line) {
    this->type = type;
    this->description = description;
    this->line = line;
    // TODO: initialize all member variables
}

std::string Token::toString() {
    std::string strtype;
    switch(type){
        case TokenType::COLON:
            strtype = "COLON";
            break;
        case TokenType::COLON_DASH:
            strtype = "COLON_DASH";
            break;
        case TokenType::COMMA:
            strtype = "COMMA";
            break;
        case TokenType::PERIOD:
            strtype = "PERIOD";
            break;
        case TokenType::Q_MARK:
            strtype = "Q_MARK";
            break;
        case TokenType::LEFT_PAREN:
            strtype = "LEFT_PAREN";
            break;
        case TokenType::RIGHT_PAREN:
            strtype = "RIGHT_PAREN";
            break;
        case TokenType::MULTIPLY:
            strtype = "MULTIPLY";
            break;
        case TokenType::ADD:
            strtype = "ADD";
            break;
        case TokenType::SCHEMES:
            strtype = "SCHEMES";
            break;
        case TokenType::FACTS:
            strtype = "FACTS";
            break;
        case TokenType::RULES:
            strtype = "RULES";
            break;
        case TokenType::QUERIES:
            strtype = "QUERIES";
            break;
        case TokenType::UNDEFINED:
            strtype = "UNDEFINED";
            break;
        case TokenType::EOF_TYPE:
            strtype = "EOF";
            break;
        case TokenType::ID:
            strtype = "ID";
            break;
        case TokenType::STRING:
            strtype = "STRING";
            break;
        case TokenType::COMMENT:
            strtype = "COMMENT";
            break;
    }
    return strtype;
}
std::string Token::getDescription() {
    return description;
}
void Token::failure(string type, std::string description, int line) {
    cout << "Failure!" << endl;
    cout << "  (" << type << ",\"" << description << "\"," << line << ")";
    exit(0);
}
int Token::getLine(){
    return line;
}
