#include"executor.h"

/**
 * @brief 
 * SYNTAX: R <- CROSS relation_name relation_name
 */
bool syntacticParseCROSS(){    
    logger<<"syntacticParseCROSS"<<endl;
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
    logger<<"semanticParseCROSS"<<endl;
    if(isTable(parsedQuery.crossResultRelationName)){
        cout<<"SEMANTIC ERROR: Resultant relation already exists"<<endl;
        return false;
    } 

    if(!isTable(parsedQuery.crossFirstRelationName) || !isTable(parsedQuery.crossSecondRelationName)){
        cout<<"SEMANTIC ERROR: Cross relations don't exist"<<endl;
        return false;
    }
    return true;
}

void executeCROSS(){
    logger<<"executeCROSS"<<endl;
    return;
}