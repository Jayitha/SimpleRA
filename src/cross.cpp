#include"executor.h"

/**
 * @brief 
 * SYNTAX: R <- CROSS relation_name relation_name
 */
bool syntacticParseCROSS(){    
    logger<<"syntacticParseCROSS"<<endl;
    if(tokenizedQuery.size() != 5){
        cout<<"SYNTAX ERROR"<<endl;
        return false;
    }
    parsedQuery.queryType = CROSS;
    parsedQuery.crossResultRelationName = tokenizedQuery[0];
    parsedQuery.crossFirstRelationName = tokenizedQuery[3];
    parsedQuery.crossSecondRelationName = tokenizedQuery[4];
    return true;
}

bool semanticParseCROSS(){
    logger<<"semanticParseCROSS"<<endl;
    if(isTable(parsedQuery.crossResultRelationName)){
        cout<<"SEMANTIC ERROR: Resultant relation already exists"<<endl;
        return false;
    } 

    if(!isTable(parsedQuery.crossFirstRelationName) || !isTable(parsedQuery.crossSecondRelationName)){
        cout<<"SEMANTIC ERROR: Cross relations don't exist"<<endl;
        return false;
    }
    return true;
}

//TODO: Doesn't cross copies of same relation
void executeCROSS(){
    logger<<"executeCROSS"<<endl;

    Table *rel1 = getTable(parsedQuery.crossFirstRelationName);
    Table *rel2 = getTable(parsedQuery.crossSecondRelationName);

    vector<string> columns;
    unordered_map<string, string> rel1ToResultant;
    unordered_map<string, string> rel2ToResultant;

    for(int i=0; i < rel1->columns.size(); i++){
        string columnName = rel1->columns[i].columnName;
        if(rel2->isColumn(columnName)){
            columnName = parsedQuery.crossFirstRelationName + "_" + columnName;
        }
        columns.emplace_back(columnName);
        rel1ToResultant[rel1->columns[i].columnName] = columnName;
    }

    for(int i=0; i < rel2->columns.size(); i++){
        string columnName = rel2->columns[i].columnName;
        if(rel1->isColumn(columnName)){
            columnName = parsedQuery.crossSecondRelationName + "_" + columnName;
        }
        columns.emplace_back(columnName);
        rel2ToResultant[rel2->columns[i].columnName] = columnName;
    }

    Table *resultRel = createNewTable(parsedQuery.crossResultRelationName, columns);

    rel1->initializeCursor();

    while(rel1->getNext()){
        rel2->initializeCursor();
        for(int i=0; i < rel1->columns.size(); i++){
            string columnName = rel1->columns[i].columnName;
            resultRel->row[rel1ToResultant[columnName]] = rel1->row[columnName];
        }
        while(rel2->getNext()){
            for(int i=0; i < rel2->columns.size(); i++){
                string columnName = rel2->columns[i].columnName;
                resultRel->row[rel2ToResultant[columnName]] = rel2->row[columnName];
            }
            resultRel->writeToSourceFile();
        }
        rel2->closeFilePointer();
    }
    rel1->closeFilePointer();
    resultRel->closeFilePointer();
    return;
}