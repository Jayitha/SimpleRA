#include "global.h"

/**
 * @brief 
 * SYNTAX: CLEAR <relation_name> 
 */

bool syntacticParseCLEAR()
{
    logger.log("syntacticParseCLEAR");
    if (tokenizedQuery.size() != 2)
    {
        cout << "SYNTAX ERROR" << endl;
        return false;
    }
    parsedQuery.queryType = CLEAR;
    parsedQuery.clearRelationName = tokenizedQuery[1];
    return true;
}

bool semanticParseCLEAR()
{
    logger.log("semanticParseCLEAR");
    if (tableCatalogue.isTable(parsedQuery.clearRelationName))
        return true;
    cout << "SEMANTIC ERROR: No such relation exists" << endl;
    return false;
}

void executeCLEAR()
{
    logger.log("executeCLEAR");
    tableCatalogue.deleteTable(parsedQuery.clearRelationName);
    return;
}