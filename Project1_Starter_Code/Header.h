//
// Created by john stewart on 10/21/22.
//

#ifndef PARSER_CPP_HEADER_H
#define PARSER_CPP_HEADER_H
#include <string>
#include <vector>

class Header {
private:
    std::vector<std::string> attributeValues;
public:
    void setAttributesValues (std::vector<std::string>att);
    void setSingleAttribute(std::string att);
    std::vector<std::string> getAllAttributeValues();
    std::string getSingleAttributeValue();
    bool isEmpty(); // return attribute values empty
};


#endif //PARSER_CPP_HEADER_H
