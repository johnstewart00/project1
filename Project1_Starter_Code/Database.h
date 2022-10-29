//
// Created by john stewart on 10/21/22.
//

#ifndef PARSER_CPP_DATABASE_H
#define PARSER_CPP_DATABASE_H

#include "Relation.h"
#include <string>
#include <map>

class Database {
public:
   std::map<std::string, Relation*> getRelations();
   void Insert(std::string, Relation*);
   std::map<std::string,Relation*> relations; // string is name of scheme, each scheme will have its own relation in the database

private:
};


#endif //PARSER_CPP_DATABASE_H
