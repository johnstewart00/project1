//
// Created by stewj on 9/24/2022.
//

#include "stringAutomaton.h"
#include <iostream>

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
    unsigned int x = index;
    if(x >= input.size()){
        Serr();
    }
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
       S1(input);
    }
    else {
        index++;
        inputRead++;
        S2(input);
//        bool wasdouble = false;
//        if(input[index+1] == '\'') wasdouble = true;
//        std::cout << "this is the input at index " << input[index] << std::endl;
//        std::cout << "this is the input at index+1 " << input[index+1] << std::endl;
//        while(input[index+1] == '\'') {
//            inputRead++;
//            index++;
//        }
//        if(wasdouble){
//            size_t b = input.substr(index+1).find("\'");
//            if (b == std::string::npos) {
//                //invalid string
//                Serr();
//            }
//            else {
//                S1(input);
//            }
//        }
//        else {
//            inputRead++;
//            index++;
//        }
   }
}

void stringAutomaton::S2(const std::string & input){
    if(input[index] == '\'') {
        index++;
        inputRead++;
        S1(input);
    }
}
