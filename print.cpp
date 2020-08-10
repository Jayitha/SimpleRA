#include"executor.h"

bool syntacticParsePRINT(){
    if(tokenizedQuery.size() != 2){
        cout<<"SYNTAX ERROR"<<endl;
        return false;
    }
    parsedQuery.queryType = PRINT;
    parsedQuery.printRelationName = tokenizedQuery[1];
    return true;
}

bool semanticParsePRINT(){
    return true;
}

void executePRINT(){
    return;
}
