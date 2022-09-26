//
// Created by stewj on 9/20/2022.
//

#include "Facts.h"
void Facts::S0(const std::string& input){
    if(input[index] == 'F'){
        inputRead++;
        index++;
        S1(input);
    }
    else{
        Serr();
    }
}
void Facts::S1(const std::string& input){
    if(input[index] == 'a'){
        inputRead++;
        index++;
        S2(input);
    }
    else{
        Serr();
    }
}
void Facts::S2(const std::string& input){
    if(input[index] == 'c'){
        inputRead++;
        index++;
        S3(input);
    }
    else{
        Serr();
    }
}
void Facts::S3(const std::string& input){
    if(input[index] == 't'){
        inputRead++;
        index++;
        S4(input);
    }
    else{
        Serr();
    }
}
void Facts::S4(const std::string& input){
    if(input[index] == 's'){
        inputRead++;
        index++;
    }
    else{
        Serr();
    }
}

