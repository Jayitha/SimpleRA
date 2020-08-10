#include"executor.h"

bool syntacticParseSELECTION(){
    if(tokenizedQuery.size()!=8 || tokenizedQuery[6]!="FROM"){
        cout<<"SYNTAC ERROR"<<endl;
        return false;
    }
    parsedQuery.queryType = SELECTION;
    parsedQuery.selectionResultRelationName = tokenizedQuery[0];
    parsedQuery.selectionFirstColumnName = tokenizedQuery[3];
    parsedQuery.selectionRelationName = tokenizedQuery[7];

    string binaryOperator = tokenizedQuery[4];
    if(binaryOperator == "<")
        parsedQuery.binaryOperator = LESS_THAN;
    else if(binaryOperator == ">")
        parsedQuery.binaryOperator = GREATER_THAN;
    else if(binaryOperator == ">=" || binaryOperator == "=>")
        parsedQuery.binaryOperator = GEQ;
    else if(binaryOperator == "<=" || binaryOperator == "=<")
        parsedQuery.binaryOperator = LEQ;
    else if(binaryOperator == "==")
        parsedQuery.binaryOperator = EQUAL;
    else if(binaryOperator == "!=")
        parsedQuery.binaryOperator = NOT_EQUAL;
    else{
        cout<<"SYNTAC ERROR"<<endl;
        return false;
    }
    
    return;
}

bool semanticParseSELECTION(){
    return true;
}

void executeSELECTION(){
    return;
}