#include"executor.h"

/**
 * @brief 
 * SYNTAX: CLEAR <relation_name> 
 */

bool syntacticParseCLEAR(){
    logger<<"syntacticParseCLEAR"<<endl;
    if(tokenizedQuery.size() != 2){
        cout<<"SYNTAX ERROR"<<endl;
        return false;
    }
    parsedQuery.queryType = CLEAR;
    parsedQuery.clearRelationName = tokenizedQuery[1];
    return true;
}

bool semanticParseCLEAR(){
    logger<<"semanticParseCLEAR"<<endl;
    if(isTable(parsedQuery.clearRelationName))
        return true;
    cout<<"SEMANTIC ERROR: No such relation exists"<<endl;
    return false;
}

void executeCLEAR(){
    logger<<"executeCLEAR"<<endl;
    return;
}