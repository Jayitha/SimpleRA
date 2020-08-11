#include"executor.h"
/**
 * @brief 
 * SYNTAX: LOAD relation_name
 */
bool syntacticParseLOAD(){
    if(tokenizedQuery.size() != 2){
        cout<<"SYNTAX ERROR"<<endl;
        return false;
    }
    parsedQuery.queryType = LOAD;
    parsedQuery.loadRelationName = tokenizedQuery[1];
    return true;
}

bool semanticParseLOAD(){
    return true;
}

void executeLOAD(){
    return;
}