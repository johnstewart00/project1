//
// Created by john stewart on 10/21/22.
//

#ifndef PARSER_CPP_RELATION_H
#define PARSER_CPP_RELATION_H
#include <iostream>
#include "Header.h"
#include "Tuple.h"
#include <set>
using namespace std;

class Relation {
public:
    Tuple select(string Attribute, string value);
    void setName(string newname);
    void setHeader(Header* newHeader);
    void setRows(set<Tuple> newRows);
    string getName();
    Header* getHeader();
    set<Tuple> getRows();
private:
    std::string name;
    Header* header; // predicates
    set<Tuple> rows;
};


#endif //PARSER_CPP_RELATION_H
