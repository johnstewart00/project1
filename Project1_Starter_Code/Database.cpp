//
// Created by john stewart on 10/21/22.
//
#include <iostream>
using namespace std;
#include "Database.h"
#include <map>
void Database::createDatabase(DatalogProgram* output){
    vector<Predicate>schemes = output->getElement("schemes");
    cout << "list of relations to create: " << endl;
    for (unsigned int i=0; i<schemes.size(); i++){
        cout << schemes.at(i).returnID() << endl;
        Relation* newRelation = new Relation;
        newRelation->setName(schemes.at(i).returnID());
        Header* newHeader = new Header;
        vector<Parameter> schemeParameters = schemes[i].returnParameters();
        vector<string>Attributes;
        for (unsigned int i=0; i<schemeParameters.size(); i++){
            Attributes.push_back(schemeParameters.at(i).returnContent());
        }
        newHeader->setAttributesValues(Attributes);
        newRelation->setHeader(newHeader);
        set<Tuple>newRows;
        vector<Predicate>facts = output->getElement("facts");
        //cout << "Facts size is: " << facts.size() << endl;
        for(unsigned int j=0; j<facts.size(); j++){
            //cout << "in facts vector for " << facts.at(j).returnID() << endl;
            if(facts.at(j).returnID() == schemes.at(i).returnID()){
                //cout << "they matched" << endl;
                Tuple newTuple;
                vector<Parameter>factsParameters = facts[j].returnParameters();
                vector<string>values;
                for (unsigned int i=0; i<factsParameters.size(); i++){
                    //cout << "added parameter as a row value" << endl;
                    values.push_back(factsParameters.at(i).returnContent());
                }
                newTuple.setValues(values);
                newRows.insert(newTuple);
            }
        }
        newRelation->setRows(newRows);
        relations.insert(std::pair<string, Relation*>(schemes.at(i).returnID(), newRelation));
    }
}
void Database::printDatabase(){
    cout << "Printing Database" << endl;
   map<string, Relation*>::iterator it;
    for (it = relations.begin(); it != relations.end(); it++){
        cout << "Relation name is: " << it->first << endl;
        vector<string> HeaderAttributes = it->second->getHeader()->getAllAttributeValues();
        cout << "Attributes: " << endl;
        int index =0;
        for (unsigned int i=0; i<HeaderAttributes.size(); i++){
           cout << HeaderAttributes[i] << endl;
           set<Tuple> Rows = it->second->getRows();
           set<Tuple>::iterator iter;
            for(iter = Rows.begin(); iter != Rows.end(); iter++){
                vector<string>nowValues = iter->getValues();
                cout << nowValues.at(index);
                cout << endl;
            }
            index++;
        }
        cout << endl;
   }
}

