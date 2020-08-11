#include"executor.h"
/**
 * @brief 
 * SYNTAX: LIST TABLES
 */
bool syntacticParseLIST(){

    if(tokenizedQuery.size() != 2 || tokenizedQuery[1] != "TABLES"){
        cout<<"SYNTAX ERROR"<<endl;
        return false;
    }
    parsedQuery.queryType = LIST;
    return true;
}

bool semanticParseLIST(){
    return true;
}

void executeLIST(){
    cout<<"\nRELATIONS"<<endl;

    int rowCount = 0;
    for(auto rel: tableIndex){
        cout<<rel.first<<endl;
        rowCount++;
    }
    printRowCount(rowCount);
}