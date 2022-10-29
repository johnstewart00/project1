#include "Lexer.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Token.h"
#include "Parser.h"
#include "DatalogProgram.h"
#include <vector>
#include "Database.h"
#include "Interpreter.h"
//#include "Automaton.h"

using namespace std;

int main(int argc, char** argv) {

    ifstream ifs(argv[1]);
    string input;
    while (!ifs.eof()){
        string line;
        getline(ifs,line);
        input+= line+(ifs.eof() ? "" : "\n");
    }
    Lexer* lexer = new Lexer();

    vector<Token*>tokenVector = lexer->Run(input);// TODO
    Parser* parse = new Parser();
//    for (int i=0; i<tokenVector.size(); i++){
//        cout << "tokenType: " << tokenVector[i]->toString() << endl;
//        cout << "Description: " << tokenVector[i]->getDescription() << endl << endl;
//    }
    DatalogProgram* output = parse->Parse(tokenVector);
    output->ToString();
    Interpreter* newinterpreter = new Interpreter;
    Database* newDatabase = new Database;
    newDatabase  = newinterpreter->createDatabase(output);
    newinterpreter->printDatabase(newDatabase);
    newinterpreter->EvaluateAllQueries(output);

    return 0;
}