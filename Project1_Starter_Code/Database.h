//
// Created by john stewart on 10/21/22.
//

#ifndef PARSER_CPP_DATABASE_H
#define PARSER_CPP_DATABASE_H
#include <map>
#include "Relation.h"
#include <string>
#include "DatalogProgram.h"
#include "Predicate.h"
#include "Header.h"
#include "Tuple.h"
#include <map>

class Database {
public:
    void createDatabase(DatalogProgram* output);
    void printDatabase();
private:
    std::map<std::string,Relation*> relations; // string is name of scheme, each scheme will have its own relation in the database
};


#endif //PARSER_CPP_DATABASE_H
