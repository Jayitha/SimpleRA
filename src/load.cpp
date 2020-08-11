#include"executor.h"
/**
 * @brief 
 * SYNTAX: LOAD relation_name
 */
bool syntacticParseLOAD(){
    logger<<"syntacticParseLOAD"<<endl;
    if(tokenizedQuery.size() != 2){
        cout<<"SYNTAX ERROR"<<endl;
        return false;
    }
    parsedQuery.queryType = LOAD;
    parsedQuery.loadRelationName = tokenizedQuery[1];
    return true;
}

bool semanticParseLOAD(){
    logger<<"semanticParseLOAD"<<endl;
    if(isTable(parsedQuery.loadRelationName)){
        cout<<"SEMANTIC ERROR: Relation already exists"<<endl;
        return false;
    }

    if(!isFileExists(parsedQuery.loadRelationName)){
        cout<<"SEMANTIC ERROR: Data file doesn't exist"<<endl;
        return false;
    }
    return true;
}

void executeLOAD(){
    logger<<"executeLOAD"<<endl;

    Table *rel = new Table(parsedQuery.loadRelationName);
    if(!rel->load())
        delete &rel;
    else{
        tableIndex[parsedQuery.loadRelationName] = rel;
        cout<<"Loaded Table. Column Count: "<<rel->columns.size()<<" Row Count: "<<rel->rowCount<<endl;
    }
    return;
}