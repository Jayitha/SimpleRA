#include"executor.h"
/**
 * @brief 
 * SYNTAX: LIST TABLES
 */
bool syntacticParseLIST(){
    logger<<"syntacticParseLIST"<<endl;
    if(tokenizedQuery.size() != 2 || tokenizedQuery[1] != "TABLES"){
        cout<<"SYNTAX ERROR"<<endl;
        return false;
    }
    parsedQuery.queryType = LIST;
    return true;
}

bool semanticParseLIST(){
    logger<<"semanticParseLIST"<<endl;
    return true;
}

void executeLIST(){
    logger<<"executeLIST"<<endl;
    cout<<"\nRELATIONS"<<endl;

    int rowCount = 0;
    for(auto rel: tableIndex){
        cout<<rel.first<<endl;
        rowCount++;
    }
    printRowCount(rowCount);
}