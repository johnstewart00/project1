//
// Created by john stewart on 10/6/22.
//

#include "Parameter.h"
#include <string>

void Parameter::setContent(string newContent) {
    content = newContent;
    if(newContent.at(0) == '\'' && newContent.at(newContent.size()-1) == '\''){
        isConstant = true;
    }
}
string Parameter::returnContent(){
    return content;
}

