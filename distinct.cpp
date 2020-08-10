#include"executor.h"

bool syntacticParseDISTINCT(){

    if(tokenizedQuery.size() != 4){
        cout<<"SYNTAX ERROR"<<endl;
        return false;
    }
    parsedQuery.queryType = DISTINCT;
    parsedQuery.distinctResultRelationName = tokenizedQuery[0];
    parsedQuery.distinctRelationName = tokenizedQuery[3];
    return true;
}

bool semanticParseDISTINCT(){
    return true;
}

void executeDISTINCT(){
    return;
}