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
    for(int i = 0; i<schemes.size(); i++){
        vector<Parameter> schemeParameters = schemes[i].returnParameters();
        if(schemeParameters.size() == 0) cout << "its empty" << endl;
        cout << "  " << schemes[i].returnID() << '(';
        for (int j=0; j<schemeParameters.size(); j++){
            cout << schemeParameters[j].returnContent();
            if(j != schemeParameters.size()-1) cout << ',';
        }
        cout << ')' << endl;
    }
    cout << "Facts(" << facts.size() << "):" << endl;
    for(int i = 0; i<facts.size(); i++){
        vector<Parameter> factParameters = facts[i].returnParameters();
        if(factParameters.size() == 0) cout << "its empty" << endl;
        cout << "  " << facts[i].returnID() << '(';
        for (int j=0; j<factParameters.size(); j++){
            cout << factParameters[j].returnContent();
            if(j != factParameters.size()-1) cout << ',';

        }
        cout << ")." << endl;
    }
    cout << "Rules(" << rules.size() << "):" << endl;
    for(int i = 0; i<rules.size(); i++){
        Predicate temp = rules[i].getHead();
        cout <<"  " << temp.returnID() << '(';
        vector<Parameter> headParameters = temp.returnParameters();
        for (int i=0; i<headParameters.size(); i++){
            cout << headParameters[i].returnContent();
            if(i != headParameters.size()-1) cout << ',';

        }
        cout << ") :- ";
        vector<Predicate*> rulePredicates = rules[i].returnPredicates();
        for (int j=0; j<rulePredicates.size(); j++){
            cout << rulePredicates[j]->returnID() << '(';
            vector<Parameter> bodyParameters = rulePredicates[j]->returnParameters();
            for (int k=0; k<bodyParameters.size(); k++){
                cout << bodyParameters[k].returnContent();
                if(k != bodyParameters.size()-1) cout << ',';
            }
            cout << ')';
            if(j != rulePredicates.size()-1){
                cout << ",";
            }
        }
        cout <<'.' <<  endl;
    }
    cout << "Queries(" << queries.size() << "):" << endl;
    for(int i = 0; i<queries.size(); i++){
        vector<Parameter> schemeParameters = queries[i].returnParameters();
        if(schemeParameters.size() == 0) cout << "its empty" << endl;
        cout << "  " << queries[i].returnID() << '(';
        for (int j=0; j<schemeParameters.size(); j++){
            cout << schemeParameters[j].returnContent();
            if(j != schemeParameters.size()-1) cout << ',';
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

