#include "Lexer.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Token.h"
#include "Parser.h"
#include "DatalogProgram.h"
#include <vector>
#include "Database.h"
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
    Database* database = new Database();
    database->createDatabase(output);
    database->printDatabase();

    return 0;
}