//
// Created by john stewart on 10/28/22.
//

#include "Interpreter.h"

Database* Interpreter::createDatabase(DatalogProgram* output){
    Database* newDatabase = new Database;
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
        newDatabase->Insert(schemes.at(i).returnID(), newRelation);
    }
    database = *newDatabase;
    return newDatabase;
}
void Interpreter::printDatabase(Database* data){
    cout << "Printing Database" << endl;
    map<string, Relation*>::iterator it;
    map<string, Relation*> relationsCopy = data->getRelations();
    for (it = relationsCopy.begin(); it != relationsCopy.end(); it++){
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
void Interpreter::EvaluateQuery(Predicate query){
    cout << query.returnID() << '(';
    Relation specifiedRel = *database.relations.at(query.returnID());
    vector<Parameter>queryParameters = query.returnParameters();
    for (unsigned int i=0; i< queryParameters.size(); i++){
        cout << queryParameters.at(i).returnContent();
        if(i != queryParameters.size()-1) cout << ',';
    }
    cout << ')';
    if(queryParameters.at(0).isConstant == false){ // strings are constants, otherwise its an ID
        specifiedRel.select(queryParameters.at(0).returnContent(),queryParameters.at(1).returnContent());
    }
    cout << endl;
}
void Interpreter::EvaluateAllQueries(DatalogProgram* output){
    vector<Predicate>queries = output->getElement("queries");
    for( unsigned int i=0; i< queries.size(); i++){
        EvaluateQuery(queries[i]);
    }
}