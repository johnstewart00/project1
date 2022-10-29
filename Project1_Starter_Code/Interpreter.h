//
// Created by john stewart on 10/28/22.
//

#ifndef PARSER_CPP_INTERPRETER_H
#define PARSER_CPP_INTERPRETER_H
#include "DatalogProgram.h"
#include "Database.h"
#include "Relation.h"
#include "Header.h"
#include "Parameter.h"
#include "Predicate.h"
#include <map>
using namespace std;

class Interpreter {
public:
    Database database;
    Database* createDatabase(DatalogProgram* output);
    void printDatabase(Database* data);
    void EvaluateQuery(Predicate query);
    void EvaluateAllQueries(DatalogProgram* output);
};


#endif //PARSER_CPP_INTERPRETER_H
