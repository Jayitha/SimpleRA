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

    public:

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


    ParsedQuery(){
        this->clear();
    }

    void clear();
    void setQueryType(QueryType QueryType);
};

extern vector<string> tokenizedQuery;
extern ParsedQuery parsedQuery;

void parseCommand();
void parseCLEAR();
void parseCROSS();
void parseDISTINCT();
void parseINDEX();
void parseLIST();
void parseLOAD();
void parsePRINT();
void parsePROJECTION();
void parseRENAME();
void parseSELECTION();
void parseSORT();

