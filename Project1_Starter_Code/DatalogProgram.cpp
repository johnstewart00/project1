//
// Created by john stewart on 10/6/22.
//

#include "DatalogProgram.h"
#include <iostream>

std::string DatalogProgram::ToString() {
    return "Datalog ToString function";
}

void DatalogProgram::push_back(Predicate* userPredicate, std::string type) {
    try {
        if (type == "schemes") {
            schemes.push_back(*userPredicate);
        } else if (type == "facts") {
            facts.push_back(*userPredicate);
        } else if (type == "queries") {
            queries.push_back(*userPredicate);
        } else {
            throw(userPredicate);
        }
    } catch(Predicate* error){
        std::cout << "wrong input type" << endl;
        exit(0);
    }
}
void DatalogProgram::addRule(Rule* newrule){
    rules.push_back(*newrule);
}
