#include"executor.h"
/**
 * @brief 
 * SYNTAX: R <- PROJECT column_name1, ... FROM relation_name
 */
bool syntacticParsePROJECTION(){
    logger<<"syntacticParsePROJECTION"<<endl;
    if(tokenizedQuery.size() < 5 || *(tokenizedQuery.end()-2) != "FROM"){
        cout<<"SYNTAX ERROR"<<endl;
        return false;
    }
    parsedQuery.queryType = PROJECTION;
    parsedQuery.projectionResultRelationName = tokenizedQuery[0];
    parsedQuery.projectionRelationName = tokenizedQuery[tokenizedQuery.size()-1];
    for(int i=3; i<tokenizedQuery.size()-2; i++)
        parsedQuery.projectionColumnList.emplace_back(tokenizedQuery[i]);
    return true;
}

bool semanticParsePROJECTION(){
    logger<<"semanticParsePROJECTION"<<endl;
    return true;
}

void executePROJECTION(){
    logger<<"executePROJECTION"<<endl;
    return;
}