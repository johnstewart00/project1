//
// Created by stewj on 9/24/2022.
//

#include "stringAutomaton.h"

void stringAutomaton::S0(const std::string& input){
    if (input[index] == '\''){
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void stringAutomaton::S1(const std::string& input){
    if(input[index]!= '\''){
        if(input[index] == '\n'){
            newLines++;
        }
        inputRead++;
        index++;
        size_t f = input.substr(index).find("\'");
        if( f == std::string::npos){
            Serr();
            return;
        }
//        unsigned int x = index;
//        if(x == input.size()){
//            Serr();
//        }
       S1(input);
    }
    else {
        if(input[index+1] == '\'') {
            inputRead++;
            index++;
            size_t b = input.substr(index+1).find("\'");
            if (b == std::string::npos) {
                //invalid string
                Serr();
            }
            else {
                S1(input);
            }
        }
        else {
            inputRead++;
            index++;
        }
    }
}
