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

    if(isTable(parsedQuery.projectionResultRelationName)){
        cout<<"SEMANTIC ERROR: Resultant relation already exists"<<endl;
        return false;
    }

    if(!isTable(parsedQuery.projectionRelationName)){
        cout<<"SEMANTIC ERROR: Relation doesn't exist"<<endl;
        return false;
    }

    Table *rel = getTable(parsedQuery.projectionRelationName);
    for(auto col: parsedQuery.projectionColumnList){
        if(!rel->isColumn(col)){
            cout<<"SEMANTIC ERROR: Column doesn't exist in relation";
            return false;
        }
    }
    return true;
}

void executePROJECTION(){
    logger<<"executePROJECTION"<<endl;

    return;
}