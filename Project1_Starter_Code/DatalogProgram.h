//
// Created by john stewart on 10/6/22.
//

#ifndef PROJECT1_STARTER_CODE_DATALOGPROGRAM_H
#define PROJECT1_STARTER_CODE_DATALOGPROGRAM_H

#include "Predicate.h"
#include "Rule.h"
#include <vector>
#include "Token.h"
#include <set>
using namespace std;

class DatalogProgram {
public:
    void push_back(Predicate*, string);
    void ToString();
    void addRule(Rule* newrule);
    void insertDomain(string element);
    vector<Predicate> getElement(string type);
    vector<Rule> getRules();
private:
    std::vector<Predicate> schemes;
    vector<Predicate> facts;
    vector<Rule> rules;
    vector<Predicate> queries;
    set<string> domain;
};


#endif //PROJECT1_STARTER_CODE_DATALOGPROGRAM_H
