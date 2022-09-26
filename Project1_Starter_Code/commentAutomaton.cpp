//
// Created by stewj on 9/24/2022.
//

#include "commentAutomaton.h"
void commentAutomaton::S0(const std::string &input) {
    if(input[index] == '#'){
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void commentAutomaton::S1(const std::string &input) {
    if(input[index] == '|'){
        index++;
        inputRead++;
        S2(input);
    }
    else {
        index++;
        inputRead++;
        S4(input);
    }
}
void commentAutomaton::S2(const std::string& input){
    // this is for block comments
    unsigned int y = inputRead;
    if(y >= input.size()){
        type =  TokenType::UNDEFINED;
        return;
    }
    if(input[index] != '|'){
        if(input[index] == '\n'){
            newLines++;
        }
        index++;
        inputRead++;


//        size_t f = input.substr(index).find("|");
//        if( f == std::string::npos){   // recently commented out
//            Serr();
//            return;
//        } // recently commented out to here
//        unsigned int x = index;
//        if(x == input.size()){ // index is as big as file, comment is incomplete
//            Serr();
//        }
        S2(input);
    }
    else {
        index++;
        inputRead++;
        S3(input);
    }
}
void commentAutomaton::S3(const std::string& input){
    if(input[index] == '#'){
        index++;
        inputRead++;
    }
    else {
        if(input[index] == '\n') newLines++;
        index++;
        inputRead++;
        S2(input);
    }
}
void commentAutomaton::S4(const std::string& input){
    if(input[index]!='\n' and input[index] != EOF){
        index++;
        inputRead++;
        S4(input);
    }
    else {
        index++;
    }
}
