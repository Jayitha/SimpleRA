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
    return true;
}

void executeCROSS(){
    logger<<"executeCROSS"<<endl;
    return;
}