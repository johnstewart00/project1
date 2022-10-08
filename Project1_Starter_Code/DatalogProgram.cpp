//
// Created by john stewart on 10/6/22.
//

#include "DatalogProgram.h"
#include <iostream>

void DatalogProgram::ToString() {
    cout << "Success!" << endl;

    cout << "Schemes(" << schemes.size() << "):" << endl;
    for(int i = 0; i<schemes.size(); i++){
        vector<Parameter> schemeParameters = schemes[i].returnParameters();
        if(schemeParameters.size() == 0) cout << "its empty" << endl;
        cout << '\t' << schemes[i].returnID() << '(';
        for (int j=0; j<schemeParameters.size(); j++){
            cout << schemeParameters[j].returnContent() << ',';
        }
        cout << ')' << endl;
    }
    cout << "Facts(" << facts.size() << "):" << endl;
    for(int i = 0; i<facts.size(); i++){
        vector<Parameter> schemeParameters = facts[i].returnParameters();
        if(schemeParameters.size() == 0) cout << "its empty" << endl;
        cout << '\t' << facts[i].returnID() << '(';
        for (int j=0; j<schemeParameters.size(); j++){
            cout << schemeParameters[j].returnContent() << ',';
        }
        cout << ")." << endl;
    }
    return;
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
