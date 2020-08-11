#include"executor.h"

/**
 * @brief 
 * SYNTAX: R <- DISTINCT relation_name
 */
bool syntacticParseDISTINCT(){
    logger<<"syntacticParseDISTINCT"<<endl;
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
    logger<<"semanticParseDISTINCT"<<endl;
    return true;
}

void executeDISTINCT(){
    logger<<"executeDISTINCT"<<endl;
    return;
}