#include"executor.h"

bool syntacticParseINDEX(){

    if(tokenizedQuery.size() != 7 || tokenizedQuery[1] != "ON" 
    || tokenizedQuery[3]!= "FROM" || tokenizedQuery[5] != "USING"){
        cout<<"SYNTAX ERROR"<<endl;
        return false;
    }
    parsedQuery.queryType = INDEX;
    parsedQuery.indexColumnName = tokenizedQuery[2];
    parsedQuery.indexRelationName = tokenizedQuery[4];
    string indexingStrategy = tokenizedQuery[6];
    if(indexingStrategy == "BTREE")
        parsedQuery.indexingStrategy = BTREE;
    else if(indexingStrategy == "HASH")
        parsedQuery.indexingStrategy = HASH;
    else if(indexingStrategy == "NOTHING")
        parsedQuery.indexingStrategy = NOTHING;
    else{
        cout<<"SYNTAX ERROR"<<endl;
        return false;
    }
    return true;
}

bool semanticParseINDEX(){
    return true;
}

void executeINDEX(){
    return;
}