#include"executor.h"
/**
 * @brief 
 * SYNTAX: R <- SELECT column_name bin_op [column_name | int_literal] FROM relation_name
 */
bool syntacticParseSELECTION(){
    logger<<"syntacticParseSELECTION"<<endl;
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
    regex numeric ("[-]?[0-9]+");
    string secondArgument = tokenizedQuery[5];
    if(regex_match(secondArgument, numeric)){
        parsedQuery.selectType = INT_LITERAL;
        parsedQuery.selectionIntLiteral = stoi(secondArgument);
    } else {
        parsedQuery.selectType = COLUMN;
        parsedQuery.selectionSecondColumnName = secondArgument;
    }
    return true;
}

bool semanticParseSELECTION(){
    logger<<"semanticParseSELECTION"<<endl;

    if(isTable(parsedQuery.selectionResultRelationName)){
        cout<<"SEMANTIC ERROR: Resultant relation already exists"<<endl;
        return false;
    }

    if(!isTable(parsedQuery.selectionRelationName)){
        cout<<"SEMANTIC ERROR: Relation doesn't exist"<<endl;
        return false;
    }

    if(!isColumnFromTable(parsedQuery.selectionFirstColumnName, parsedQuery.selectionRelationName)){
        cout<<"SEMANTIC ERROR: Column doesn't exist in relation"<<endl;
        return false;
    }

    if(parsedQuery.selectType == COLUMN){
        if(!isColumnFromTable(parsedQuery.selectionSecondColumnName, parsedQuery.selectionRelationName)){
            cout<<"SEMANTIC ERROR: Column doesn't exist in relation"<<endl;
            return false;
        }
    }
    return true;
}

void executeSELECTION(){
    logger<<"executeSELECTION"<<endl;
    return;
}