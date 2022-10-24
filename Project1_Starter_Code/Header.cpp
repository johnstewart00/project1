//
// Created by john stewart on 10/21/22.
//

#include "Header.h"

void Header::setAttributesValues(std::vector<std::string> att) {
    for (unsigned int i=0; i< att.size(); i++){
        attributeValues.push_back(att.at(i));
    }
}
std::vector<std::string> Header::getAllAttributeValues(){
    return attributeValues;
}
