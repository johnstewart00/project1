//
// Created by john stewart on 10/21/22.
//

#ifndef PARSER_CPP_DATABASE_H
#define PARSER_CPP_DATABASE_H
#include <map>
#include "Relation.h"
#include <string>

class Database {
private:
    std::map<std::string,Relation*> relations; // string is name of scheme
};


#endif //PARSER_CPP_DATABASE_H
