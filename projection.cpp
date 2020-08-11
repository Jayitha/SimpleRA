#include"executor.h"
/**
 * @brief 
 * SYNTAX: R <- PROJECT column_name1, ... FROM relation_name
 */
bool syntacticParsePROJECTION(){
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
    return true;
}

void executePROJECTION(){
    return;
}