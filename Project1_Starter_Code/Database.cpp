//
// Created by john stewart on 10/21/22.
//
#include <iostream>
using namespace std;
#include "Database.h"
#include <map>

std::map<std::string, Relation*> Database::getRelations(){
    return relations;
}
void Database::Insert(std::string newString, Relation* newRelation){
    relations.insert(std::pair<std::string, Relation*>(newString, newRelation));
}
