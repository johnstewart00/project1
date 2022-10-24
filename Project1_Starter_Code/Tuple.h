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
    vector<string> getValues() const;
    void setValues(vector<string> newValues);
    bool operator< (const Tuple &rhs) const{ // removed const from before the {
        return values < rhs.values;
    }
};


#endif //PARSER_CPP_TUPLE_H
