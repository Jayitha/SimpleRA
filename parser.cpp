#include"executor.h"

using namespace std;

void parseCommand(){

    string possibleQueryType = tokenizedQuery[0];

    if(possibleQueryType == "CLEAR")
        parseCLEAR();
    else if(possibleQueryType == "INDEX")
        parseINDEX();
    else if(possibleQueryType == "LIST")
        parseLIST();
    else if(possibleQueryType == "LOAD")
        parseLOAD();
    else if(possibleQueryType == "PRINT")
        parsePRINT();
    else if(possibleQueryType == "RENAME")
        parseRENAME();

    else{
        if(tokenizedQuery[1] != "<-" || tokenizedQuery.size() < 3){
            cout<<"SYNTAX ERROR"<<endl;
            return;
        } 
        possibleQueryType = tokenizedQuery[2];
        if(possibleQueryType == "PROJECT")
            parsePROJECTION();
        else if(possibleQueryType == "SELECT")
            parseSELECTION();
        else if(possibleQueryType == "CROSS")
            parseCROSS();
        else if(possibleQueryType == "DISTINCT")
            parseDISTINCT();
        else if(possibleQueryType == "SORT")
            parseSORT();
        else{
            cout<<"SYNTAX ERROR"<<endl;
            return;
        }
    }
    return;   
}

void parseCLEAR(){

    parsedQuery.queryType = CLEAR;
    return;
}

void parseCROSS(){

    parsedQuery.queryType = CROSS;
    return;
}

void parseDISTINCT(){

    parsedQuery.queryType = DISTINCT;
    return;
}

void parseINDEX(){

    parsedQuery.queryType = INDEX;
    return;
}

void parseLIST(){

    parsedQuery.queryType = LIST;
    if(tokenizedQuery[1] != "TABLES"){
        cout<<"SYNTAX ERROR"<<endl;
        return;
    }
    return;
}

void parseLOAD(){

    parsedQuery.queryType = LOAD;
    return;
}

void parsePRINT(){

    parsedQuery.queryType = PRINT;
    return;
}

void parsePROJECTION(){

    parsedQuery.queryType = PROJECTION;
    return;
}

void parseRENAME(){

    parsedQuery.queryType = RENAME;
    return;
}

void parseSELECTION(){

    parsedQuery.queryType = SELECTION;
    return;
}

void parseSORT(){

    parsedQuery.queryType = SORT;
    return;
}

void ParsedQuery::clear(){
        this->queryType = UNDETERMINED;
        this->indexingStrategy = NOTHING;
        this->binaryOperator = NO_BINOP_CLAUSE;
        this->sortingStrategy = NO_SORT_CLAUSE;
        this->targetRelationName = "";
        this->secondTargetRelationName = "";
        this->targetColumnName = "";
        this->secondTargetColumnName = "";
        this->resultantRelationName = "";
        this->projectionColumnList.clear();
        this->newColumnName = "";
        this->intLiteral = 0;
}