//
// Created by john stewart on 10/21/22.
//

#ifndef PARSER_CPP_TUPLE_H
#define PARSER_CPP_TUPLE_H
#include <vector>
#include <string>
using namespace std;

class Tuple {
private:
    vector<string> values;
public:
    bool operator< (const Tuple & other) const {
        return false; // change this
    }
};


#endif //PARSER_CPP_TUPLE_H