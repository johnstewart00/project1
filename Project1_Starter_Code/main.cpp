#include "Lexer.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Token.h"
#include <vector>
//#include "Automaton.h"

using namespace std;

int main(int argc, char** argv) {

    ifstream ifs(argv[1]);
    //string test = "C:\\Users\\stewj\\html\\test.txt";
   // ifstream ifs(test);
    string input;
    while (!ifs.eof()){
        string line;
        getline(ifs,line);
        input+= line+(ifs.eof() ? "" : "\n");
    }
    Lexer* lexer = new Lexer();

    vector<Token*>tokenVector = lexer->Run(input);// TODO


    return 0;
}