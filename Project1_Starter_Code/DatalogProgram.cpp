//
// Created by john stewart on 10/6/22.
//

#include "DatalogProgram.h"

std::string DatalogProgram::ToString() {
    return "here";
}

void DatalogProgram::push_back(Predicate* userPredicate, std::string type) {
    if(type == "schemes"){
        schemes.push_back(*userPredicate);
    }
}
