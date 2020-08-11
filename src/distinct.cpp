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

    if(isTable(parsedQuery.distinctResultRelationName)){
        cout<<"SEMANTIC ERROR: Resultant relation already exists"<<endl;
        return false;
    } 

    if(!isTable(parsedQuery.distinctRelationName)){
        cout<<"SEMANTIC ERROR: Relation doesn't exist"<<endl;
        return false;
    }
    return true;
}

void executeDISTINCT(){
    logger<<"executeDISTINCT"<<endl;
    return;
}