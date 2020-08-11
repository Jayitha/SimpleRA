#include"executor.h"

using namespace std;

bool syntacticParse(){
    logger<<"syntacticParse"<<endl;
    string possibleQueryType = tokenizedQuery[0];

    if(possibleQueryType.size() < 2){
        cout<<"SYNTAX ERROR"<<endl;
        return false;
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
            return false;
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

ParsedQuery::ParsedQuery(){

}

void ParsedQuery::clear(){
    logger<<"ParsedQuery::clear"<<endl;
    this->queryType = UNDETERMINED;

    this->clearRelationName = "";

    this->crossResultRelationName = "";
    this->crossFirstRelationName = "";
    this->crossSecondRelationName = "";

    this->distinctResultRelationName = "";
    this->distinctRelationName = "";

    this->indexingStrategy = NOTHING;
    this->indexColumnName = "";
    this->indexRelationName = "";

    this->loadRelationName = "";

    this->printRelationName = "";

    this->projectionResultRelationName = "";
    this->projectionColumnList.clear();
    this->projectionRelationName = "";

    this->renameFromColumnName = "";
    this->renameToColumnName = "";
    this->renameRelationName = "";

    this->selectType = NO_SELECT_CLAUSE;
    this->binaryOperator = NO_BINOP_CLAUSE;
    this->selectionResultRelationName = "";
    this->selectionRelationName = "";
    this->selectionFirstColumnName = "";
    this->selectionSecondColumnName = "";
    this->selectionIntLiteral = 0;

    this->sortingStrategy = NO_SORT_CLAUSE;
    this->sortResultRelationName = "";
    this->sortColumnName = "";
    this->sortRelationName = "";
    
}