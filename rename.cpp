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
    return true;
}

void executeRENAME(){
    logger<<"executeRENAME"<<endl;
    return;
}