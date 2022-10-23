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
private:
    std::string name;
    Header* header;
    set<Tuple> rows;
};


#endif //PARSER_CPP_RELATION_H
