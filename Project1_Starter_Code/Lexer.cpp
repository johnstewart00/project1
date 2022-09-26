#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "Add.h"
#include "CommaAutomaton.h"
#include "Facts.h"
#include "LeftParenAutomaton.h"
#include "Multiply.h"
#include "PeriodAutomaton.h"
#include "Q_MarkAutomaton.h"
#include "Queries.h"
#include "RightParen.h"
#include "Rules.h"
#include "Schemes.h"
#include <iostream>
#include <string>
#include "IDAutomaton.h"
#include "stringAutomaton.h"
#include "commentAutomaton.h"
#include "undefinedAutomaton.h"
//#include "Automaton.h"
using namespace std;
    Lexer::Lexer() {
        CreateAutomata();
    }

    Lexer::~Lexer() {
//        for (unsigned int i=0; i < automata.size(); i++){
//            delete automata.at(i);
//        }
//        for (int i=0; i<tokens.size(); i++) {
//            delete tokens.at(i);
//        }        // TODO: need to clean up the memory in `automata` and `tokens`
    }

    void Lexer::CreateAutomata() {
        automata.push_back(new ColonAutomaton());
        automata.push_back(new ColonDashAutomaton());
        automata.push_back(new Add());
        automata.push_back(new CommaAutomaton());
        automata.push_back(new Facts());
        automata.push_back(new LeftParenAutomaton());
        automata.push_back(new Multiply());
        automata.push_back(new PeriodAutomaton());
        automata.push_back(new Q_MarkAutomaton());
        automata.push_back(new Queries());
        automata.push_back(new RightParen());
        automata.push_back(new Rules());
        automata.push_back(new Schemes());
        automata.push_back(new IDAutomaton());
        automata.push_back(new stringAutomaton());
        automata.push_back(new commentAutomaton());
        automata.push_back(new undefinedAutomaton());
        // TODO: Add the other needed automata here
    }

    void Lexer::Run(string input) {
        // TODO: convert this pseudo-code with the algorithm into actual C++ code
        int lineNumber = 1;
        int maxRead = 0;
        Automaton *maxAutomaton;
        //std::cout << "here" << std::endl;
        while(input.size() > 0) {
            if (isspace(input[0])) {
                if (input[0] == '\n') {
                    lineNumber++;
                }
                input = input.substr(1);
                continue;
            }
            maxRead = 0;
            maxAutomaton = automata.at(0);
            for (unsigned int j = 0; j < automata.size(); j++) {
                int inputRead = automata.at(j)->Start(input);
                if (inputRead > maxRead) {
                    maxRead = inputRead;
                    maxAutomaton = automata.at(j);
                    if(maxAutomaton->type == TokenType::UNDEFINED){
                        maxRead = input.size();
                    }
                }

            }
            if (maxRead > 0) {

                std::string stringread = input.substr(0, maxRead);
                Token *newtoken = maxAutomaton->CreateToken(stringread, lineNumber);
                lineNumber = lineNumber + maxAutomaton->NewLinesRead();
                tokens.push_back(newtoken);
            } else {
                maxRead = 1;
                char ch = input.at(0);
                std::string description(1, ch);
                Token *newtoken = new Token(TokenType::UNDEFINED, description, lineNumber);
                tokens.push_back(newtoken);

            }
            input = input.substr(maxRead);
        }
        Token *endtoken = new Token(TokenType::EOF_TYPE, "", lineNumber);
        tokens.push_back(endtoken);
    }
        /*
        set lineNumber to 1
        // While there are more characters to tokenize
        loop while input.size() > 0 {
            set maxRead to 0
            set maxAutomaton to the first automaton in automata

            // TODO: you need to handle whitespace inbetween tokens

            // Here is the "Parallel" part of the algorithm
            //   Each automaton runs with the same input
            foreach automaton in automata {
                inputRead = automaton.Start(input)
                if (inputRead > maxRead) {
                    set maxRead to inputRead
                    set maxAutomaton to automaton
                }
            }
            // Here is the "Max" part of the algorithm
            if maxRead > 0 {
                set newToken to maxAutomaton.CreateToken(...)
                    increment lineNumber by maxAutomaton.NewLinesRead()
                    add newToken to collection of all tokens
            }
            // No automaton accepted input
            // Create single character undefined token
            else {
                set maxRead to 1
                    set newToken to a  new undefined Token
                    (with first character of input)
                    add newToken to collection of all tokens
            }
            // Update `input` by removing characters read to create Token
            remove maxRead characters from input
        }
        add end of file token to all tokens
        */


std::string Lexer::toString() {
    std::string tokenlist = "";
    for (unsigned int i=0; i < tokens.size(); i++){
        tokenlist += tokens.at(i)->toString() + "\n";
    }
    return tokenlist + "Total Tokens = " + to_string(tokens.size());
}