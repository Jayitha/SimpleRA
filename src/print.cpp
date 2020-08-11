#include"executor.h"
/**
 * @brief 
 * SYNTAX: PRINT relation_name
 */
bool syntacticParsePRINT(){
    logger<<"syntacticParsePRINT"<<endl;
    if(tokenizedQuery.size() != 2){
        cout<<"SYNTAX ERROR"<<endl;
        return false;
    }
    parsedQuery.queryType = PRINT;
    parsedQuery.printRelationName = tokenizedQuery[1];
    return true;
}

bool semanticParsePRINT(){
    logger<<"semanticParsePRINT"<<endl;
    if(!isTable(parsedQuery.printRelationName)){
        cout<<"SEMANTIC ERROR: Relation doesn't exist"<<endl;
        return false;
    }
    return true;
}

void executePRINT(){
    logger<<"executePRINT"<<endl;
    return;
}
