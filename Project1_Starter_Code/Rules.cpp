//
// Created by stewj on 9/20/2022.
//

#include "Rules.h"
void Rules::S0(const std::string& input){
    if(input[index] == 'R'){
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void Rules::S1(const std::string& input){
    if(input[index] == 'u'){
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}
void Rules::S2(const std::string& input){
    if(input[index] == 'l'){
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}
void Rules::S3(const std::string& input){
    if(input[index] == 'e'){
        inputRead++;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}
void Rules::S4(const std::string& input){
    if(input[index] == 's'){
        inputRead++;
        index++;
    }
    else {
        Serr();
    }
}

