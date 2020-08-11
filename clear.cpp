#include"executor.h"

/**
 * @brief 
 * SYNTAX: CLEAR table_name 
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
    return true;
}

void executeCLEAR(){
    logger<<"executeCLEAR"<<endl;
    return;
}