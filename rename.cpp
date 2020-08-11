#include"executor.h"
/**
 * @brief 
 * SYNTAX: RENAME column_name TO column_name FROM relation_name
 */
bool syntacticParseRENAME(){
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
    return true;
}

void executeRENAME(){
    return;
}