//
// Created by john stewart on 10/6/22.
//

#ifndef PROJECT1_STARTER_CODE_RULE_H
#define PROJECT1_STARTER_CODE_RULE_H
#include "Predicate.h"
using namespace std;

class Rule {
private:
    Predicate head;
    vector<Predicate> body;
};


#endif //PROJECT1_STARTER_CODE_RULE_H
