//
// Created by stewj on 9/24/2022.
//
#include <iostream>
#include "undefinedAutomaton.h"

void undefinedAutomaton::S0(const std::string &input) {
    if (input[index] == '\''){
        inputRead++;
        index++;
        S1(input);
    }
    else if(input[index] == '#'){
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}
void undefinedAutomaton::S1(const std::string& input){
    size_t f = input.substr(index).find("\'");
    unsigned int x = index;
    if( f == std::string::npos and x != input.size()){
        if(input[index] == '\n'){
            newLines++;
        }
        index++;
        inputRead++;
        S1(input);
    }
    else {
        size_t j = input.substr(index+f+1).find("\'");
        if( j != std::string::npos) {
            size_t k = input.substr(f+3).find('\'');
            if (k != std::string::npos) {
                Serr(); // has a '' but is still a valid string
            }
            else {
                S4(input); // special situation with '' but invalid
            }
        }
        else {
            index++;
            inputRead++;
            Serr();
        }
    }
}
void undefinedAutomaton::S2(const std::string &input) {
    if(input[index] == '|'){
        index++;
        inputRead++;
        S3(input);
    }
    else {
        Serr();
    }
}
void undefinedAutomaton::S3(const std::string &input) {
    size_t f = input.substr(index).find("|#");
    unsigned int x = index;
    if(f == std::string::npos and x != input.size()){
        if(input[index] == '\n'){
            newLines++;
        }
        index++;
        inputRead++;
        S1(input);
    }
    else {
        Serr();
    }
}
void undefinedAutomaton::S4(const std::string &input) {
    unsigned int x = index;
    if(x != input.size()) {

        if (input[index] == '\n') {
            newLines++;
        }
        index++;
        inputRead++;
        S4(input);
    }
}