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
Relation* Relation::select(string column, string value){
    Relation* specified = new Relation;
    vector<string> attributes = header->getAllAttributeValues();
    int indexOfColumn =0;
    for (unsigned int i=0; i< attributes.size(); i++){
        if(attributes.at(i) == column) indexOfColumn =i+1;
    }
    cout << "index of column selected is: " << indexOfColumn << endl;
    set<Tuple>::iterator it;
    for(it = rows.begin(); it!= rows.end(); it++){
        if(it->values.at(indexOfColumn) == value){
            specified->rows.insert(*it);
        }
    }
    cout << "made it to returning the specified relation from the query" << endl;
    if(specified->rows.size() >0) cout << "we successfully did it probs" << endl;
    return specified;
}
Relation* Relation::select(int index, int otherIndex){
    Relation* specified = new Relation;
    return specified;
}




