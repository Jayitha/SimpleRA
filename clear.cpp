#include"executor.h"

bool syntacticParseCLEAR(){

    if(tokenizedQuery.size() != 2){
        cout<<"SYNTAX ERROR"<<endl;
        return false;
    }
    parsedQuery.queryType = CLEAR;
    parsedQuery.clearRelationName = tokenizedQuery[1];
    return true;
}

bool semanticParseCLEAR(){
    return true;
}

void executeCLEAR(){
    return;
}