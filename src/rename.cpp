#include"executor.h"
/**
 * @brief 
 * SYNTAX: RENAME column_name TO column_name FROM relation_name
 */
bool syntacticParseRENAME(){
    logger<<"syntacticParseRENAME"<<endl;
    if(tokenizedQuery.size()!=6 || tokenizedQuery[2]!="TO" || tokenizedQuery[4] != "FROM"){
        cout<<"SYNTAX ERROR"<<endl;
        return false;
    }
    parsedQuery.queryType = RENAME;
    parsedQuery.renameFromColumnName = tokenizedQuery[1];
    parsedQuery.renameToColumnName = tokenizedQuery[3];
    parsedQuery.renameRelationName = tokenizedQuery[5];
    return true;
}

bool semanticParseRENAME(){
    logger<<"semanticParseRENAME"<<endl;

    if(!isTable(parsedQuery.renameRelationName)){
        cout<<"SEMANTIC ERROR: Relation doesn't exist"<<endl;
        return false;
    }

    if(!isColumnFromTable(parsedQuery.renameFromColumnName, parsedQuery.renameRelationName)){
        cout<<"SEMANTIC ERROR: Column doesn't exist in relation"<<endl;
        return false;
    }

    if(isColumnFromTable(parsedQuery.renameToColumnName, parsedQuery.renameRelationName)){
        cout<<"SEMANTIC ERROR: Column with name already exists"<<endl;
        return false;
    }
    return true;
}

void executeRENAME(){
    logger<<"executeRENAME"<<endl;
    Table *rel = getTable(parsedQuery.renameRelationName);
    rel->renameColumn(parsedQuery.renameFromColumnName, parsedQuery.renameToColumnName);
    return;
}