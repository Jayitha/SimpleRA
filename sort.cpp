#include"executor.h"
/**
 * @brief File contains method to process SORT commands.
 * 
 * syntax:
 * R <- SORT column_name FROM relation_name IN sorting_order
 * 
 * sorting_order = ASC | DESC 
 */

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool syntacticParseSORT(){

    parsedQuery.queryType = SORT;
    return;
}

bool semanticParseSORT(){
    return true;
}

void executeSORT(){
    return;
}