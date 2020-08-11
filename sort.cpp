#include"executor.h"
/**
 * @brief File contains method to process SORT commands.
 * 
 * syntax:
 * R <- SORT column_name FROM relation_name IN sorting_order
 * 
 * sorting_order = ASC | DESC 
 */
bool syntacticParseSORT(){
    if(tokenizedQuery.size()!= 8 || tokenizedQuery[4] != "FROM" || tokenizedQuery[6] != "IN"){
        cout<<"SYNTAX ERROR"<<endl;
        return false;
    }
    parsedQuery.queryType = SORT;
    parsedQuery.sortResultRelationName = tokenizedQuery[0];
    parsedQuery.sortColumnName = tokenizedQuery[3];
    parsedQuery.sortRelationName = tokenizedQuery[5];
    string sortingStrateg = tokenizedQuery[7];
    if(sortingStrateg == "ASC")
        parsedQuery.sortingStrategy = ASC;
    else if(sortingStrateg == "DESC")
        parsedQuery.sortingStrategy = DESC;
    else{
        cout<<"SYNTAX ERROR"<<endl;
        return false;
    }
    return true;
}

bool semanticParseSORT(){
    return true;
}

void executeSORT(){
    return;
}