#include"executor.h"

using namespace std;

bool syntacticParse(){

    string possibleQueryType = tokenizedQuery[0];

    if(possibleQueryType.size() < 2){
        cout<<"SYNTAX ERROR"<<endl;
        return;
    }

    if(possibleQueryType == "CLEAR")
        return syntacticParseCLEAR();
    else if(possibleQueryType == "INDEX")
        return syntacticParseINDEX();
    else if(possibleQueryType == "LIST")
        return syntacticParseLIST();
    else if(possibleQueryType == "LOAD")
        return syntacticParseLOAD();
    else if(possibleQueryType == "PRINT")
        return syntacticParsePRINT();
    else if(possibleQueryType == "RENAME")
        return syntacticParseRENAME();

    else{
        string resultantRelationName = possibleQueryType;
        if(tokenizedQuery[1] != "<-" || tokenizedQuery.size() < 3){
            cout<<"SYNTAX ERROR"<<endl;
            return;
        }
        possibleQueryType = tokenizedQuery[2];
        if(possibleQueryType == "PROJECT")
            return syntacticParsePROJECTION();
        else if(possibleQueryType == "SELECT")
            return syntacticParseSELECTION();
        else if(possibleQueryType == "CROSS")
            return syntacticParseCROSS();
        else if(possibleQueryType == "DISTINCT")
            return syntacticParseDISTINCT();
        else if(possibleQueryType == "SORT")
            return syntacticParseSORT();
        else{
            cout<<"SYNTAX ERROR"<<endl;
            return false;
        }
    }
    return false;
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