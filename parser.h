#include"table.h"

using namespace std;

enum QueryType{
    CLEAR,
    CROSS,
    DISTINCT,
    INDEX,
    LIST,
    LOAD,
    PRINT,
    PROJECTION,
    RENAME,
    SELECTION,
    SORT,
    UNDETERMINED
};

enum BinaryOperator{
    LESS_THAN,
    GREATER_THAN,
    LEQ,
    GEQ,
    EQUAL,
    NOT_EQUAL,
    NO_BINOP_CLAUSE
};

enum SortingStrategy{
    ASC,
    DESC,
    NO_SORT_CLAUSE
};

class ParsedQuery{

    QueryType queryType;
    IndexingStrategy indexingStrategy;
    BinaryOperator binaryOperator;
    SortingStrategy sortingStrategy;
    string targetRelationName;
    string secondTargetRelationName;
    string targetColumnName;
    string secondTargetColumnName;
    string resultantRelationName;
    vector<string> projectionColumnList;
    string newColumnName;
    int intLiteral;

    public:

    ParsedQuery(){
        this->clear();
    }

    void clear(){
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
};

extern ParsedQuery parsedQuery;

void parseCommand(vector<string> tokenizedCommand);
void parseCLEAR(vector<string> tokenizedCommand);
void parseCROSS(vector<string> tokenizedCommand);
void parseDISTINCT(vector<string> tokenizedCommand);
void parseINDEX(vector<string> tokenizedCommand);
void parseLIST(vector<string> tokenizedCommand);
void parseLOAD(vector<string> tokenizedCommand);
void parsePRINT(vector<string> tokenizedCommand);
void parsePROJECTION(vector<string> tokenizedCommand);
void parseRENAME(vector<string> tokenizedCommand);
void parseSELECTION(vector<string> tokenizedCommand);
void parseSORT(vector<string> tokenizedCommand);

