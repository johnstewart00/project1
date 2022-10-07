//
// Created by john stewart on 10/6/22.
//

#ifndef PROJECT1_STARTER_CODE_PREDICATE_H
#define PROJECT1_STARTER_CODE_PREDICATE_H

#include <string>
#include "Parameter.h"
#include <vector>

class Predicate {
public:
    void setID(std::string newID);
    void addParameter(Parameter*);
private:
    std::string ID;
    std::vector<Parameter>parameter;
};


#endif //PROJECT1_STARTER_CODE_PREDICATE_H
