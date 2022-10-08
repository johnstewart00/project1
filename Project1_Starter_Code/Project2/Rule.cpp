//
// Created by john stewart on 10/6/22.
//

#include "Rule.h"

void Rule::sethead(Predicate* newHead){
    head = *newHead;
    return;
}
void Rule::setbody(vector<Predicate*>newBody){
    body = newBody;
}
vector<Predicate*> Rule::returnPredicates(){
    return body;
}

Predicate Rule::getHead(){
    return head;
}



