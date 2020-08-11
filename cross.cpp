#include"executor.h"

/**
 * @brief 
 * SYNTAX: R <- CROSS relation_name relation_name
 */
bool syntacticParseCROSS(){

    if(tokenizedQuery.size() != 5){
        cout<<"SYNTAX ERROR"<<endl;
        return false;
    }
    parsedQuery.queryType = CROSS;
    parsedQuery.crossResultRelationName = tokenizedQuery[0];
    parsedQuery.crossFirstRelationName = tokenizedQuery[3];
    parsedQuery.crossSecondRelationName = tokenizedQuery[4];
    return true;
}

bool semanticParseCROSS(){
    return true;
}

void executeCROSS(){
    return;
}