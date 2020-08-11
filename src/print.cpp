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
    return true;
}

void executePRINT(){
    logger<<"executePRINT"<<endl;
    return;
}
