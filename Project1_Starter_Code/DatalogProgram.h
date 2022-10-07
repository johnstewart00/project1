//
// Created by john stewart on 10/6/22.
//

#ifndef PROJECT1_STARTER_CODE_DATALOGPROGRAM_H
#define PROJECT1_STARTER_CODE_DATALOGPROGRAM_H

#include "Predicate.h"

class DatalogProgram {
public:
    std::string ToString();
private:
    std::vector<Predicate> schemes;

};


#endif //PROJECT1_STARTER_CODE_DATALOGPROGRAM_H
