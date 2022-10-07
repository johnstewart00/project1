#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    COLON,
    COLON_DASH,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    EOF_TYPE,

    // TODO: add the other types of tokens
};

class Token
{
private:
    std::string description;
    int line;
    // TODO: add member variables for information needed by Token

public:
    std::string getDescription();
    TokenType type;
    Token();
    Token(TokenType type, std::string description, int line);
    std::string toString();
    // TODO: add other needed methods
};

#endif // TOKEN_H

