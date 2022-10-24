//
// Created by john stewart on 10/21/22.
//

#include "Relation.h"

void Relation::setName(string newname){
    name  = newname;
}
void Relation::setHeader(Header* newHeader){
    header = newHeader;
}
void Relation::setRows(set<Tuple> newRows){
    rows = newRows;
}
string Relation::getName(){
    return name;
}
Header* Relation::getHeader(){
    return header;
}
set<Tuple> Relation::getRows(){
    return rows;
}



