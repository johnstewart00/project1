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
std::string Predicate::returnID(){
    return ID;
}
vector<Parameter> Predicate::returnParameters(){
    return parameter;
}
void Predicate::setParameters(vector<Parameter> newParameters){
    parameter = newParameters;
}



