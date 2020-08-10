#include"executor.h"

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