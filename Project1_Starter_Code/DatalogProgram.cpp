//
// Created by john stewart on 10/6/22.
//

#include "DatalogProgram.h"
#include <iostream>
#include <set>
#include "Parameter.h"
#include "Token.h"

void DatalogProgram::ToString() {
    cout << "Success!" << endl;

    cout << "Schemes(" << schemes.size() << "):" << endl;
    for(unsigned int i = 0; i<schemes.size(); i++){
        vector<Parameter> schemeParameters = schemes[i].returnParameters();
        if(schemeParameters.size() == 0) cout << "its empty" << endl;
        cout << "  " << schemes[i].returnID() << '(';
        for (unsigned int j=0; j<schemeParameters.size(); j++){
            cout << schemeParameters[j].returnContent();
            unsigned int dud =1;
            if(j != schemeParameters.size()-dud) cout << ',';
        }
        cout << ')' << endl;
    }
    cout << "Facts(" << facts.size() << "):" << endl;
    for(unsigned int i = 0; i<facts.size(); i++){
        vector<Parameter> factParameters = facts[i].returnParameters();
        if(factParameters.size() == 0) cout << "its empty" << endl;
        cout << "  " << facts[i].returnID() << '(';
        for (unsigned int j=0; j<factParameters.size(); j++){
            cout << factParameters[j].returnContent();
            unsigned int dud =1;
            if(j != factParameters.size()-dud) cout << ',';

        }
        cout << ")." << endl;
    }
    cout << "Rules(" << rules.size() << "):" << endl;
    for(unsigned int i = 0; i<rules.size(); i++){
        Predicate temp = rules[i].getHead();
        cout <<"  " << temp.returnID() << '(';
        vector<Parameter> headParameters = temp.returnParameters();
        for (unsigned int i=0; i<headParameters.size(); i++){
            cout << headParameters[i].returnContent();
            unsigned int dud =1;
            if(i != headParameters.size()-dud) cout << ',';

        }
        cout << ") :- ";
        vector<Predicate*> rulePredicates = rules[i].returnPredicates();
        for (unsigned int j=0; j<rulePredicates.size(); j++){
            cout << rulePredicates[j]->returnID() << '(';
            vector<Parameter> bodyParameters = rulePredicates[j]->returnParameters();
            for (unsigned int k=0; k<bodyParameters.size(); k++){
                cout << bodyParameters[k].returnContent();
                unsigned int dud =1;
                if(k != bodyParameters.size()-dud) cout << ',';
            }
            cout << ')';
            unsigned int temp =1;
            if(j != rulePredicates.size()-temp){
                cout << ",";
            }
        }
        cout <<'.' <<  endl;
    }
    cout << "Queries(" << queries.size() << "):" << endl;
    for(unsigned int i = 0; i<queries.size(); i++){
        vector<Parameter> schemeParameters = queries[i].returnParameters();
        if(schemeParameters.size() == 0) cout << "its empty" << endl;
        cout << "  " << queries[i].returnID() << '(';
        for (unsigned int j=0; j<schemeParameters.size(); j++){
            cout << schemeParameters[j].returnContent();
            unsigned int temp =1;
            if(j != schemeParameters.size()-temp) cout << ',';
        }
        cout << ")?" << endl;
    }
    cout << "Domain(" << domain.size() << "):" << endl;
    for (auto i = domain.begin(); i != domain.end(); i++)
        cout << "  " << *i << endl;
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
void DatalogProgram::insertDomain ( string element){
    domain.insert( element);
}
vector<Predicate> DatalogProgram::getElement(std::string type) {
    if(type == "schemes"){
        return schemes;
    }
    else if (type == "facts"){
        return facts;
    }
    else if (type == "queries"){
        return queries;
    }
    else {
        cout << "you didn't get anything, ending program" << endl;
        exit(0);
    }
}
vector<Rule> DatalogProgram::getRules() {
    return rules;
}



