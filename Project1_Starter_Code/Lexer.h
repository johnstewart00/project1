#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include <string>
#include "Automaton.h"
using namespace std;

class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;

    void CreateAutomata();

    // TODO: add any other private methods here (if needed)

public:
    Lexer();
    ~Lexer();

    void Run(string input);
    std::string toString();
    
    // TODO: add other public methods here

};

#endif // LEXER_H

