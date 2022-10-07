//
// Created by john stewart on 10/6/22.
//

#include "Predicate.h"
void Predicate::setID(std::string newID){
    ID = newID;
}
void Predicate::addParameter(Parameter* newParameter){
    parameter.push_back(*newParameter);
}
