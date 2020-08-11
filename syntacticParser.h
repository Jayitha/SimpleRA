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

enum SelectType{
    COLUMN,
    INT_LITERAL,
    NO_SELECT_CLAUSE
};

class ParsedQuery{

    public:

    QueryType queryType;

    string clearRelationName;

    string crossResultRelationName;
    string crossFirstRelationName;
    string crossSecondRelationName;

    string distinctResultRelationName;
    string distinctRelationName;

    IndexingStrategy indexingStrategy;
    string indexColumnName;
    string indexRelationName;

    string loadRelationName;

    string printRelationName;

    string projectionResultRelationName;
    vector<string> projectionColumnList;
    string projectionRelationName;

    string renameFromColumnName;
    string renameToColumnName;
    string renameRelationName;

    SelectType selectType;
    BinaryOperator binaryOperator;
    string selectionResultRelationName;
    string selectionRelationName;
    string selectionFirstColumnName;
    string selectionSecondColumnName;
    int selectionIntLiteral;

    SortingStrategy sortingStrategy;
    string sortResultRelationName;
    string sortColumnName;
    string sortRelationName;

    ParsedQuery(){
        this->clear();
    }

    void clear();
    void setQueryType(QueryType QueryType);
};

extern vector<string> tokenizedQuery;
extern ParsedQuery parsedQuery;

bool syntacticParse();
bool syntacticParseCLEAR();
bool syntacticParseCROSS();
bool syntacticParseDISTINCT();
bool syntacticParseINDEX();
bool syntacticParseLIST();
bool syntacticParseLOAD();
bool syntacticParsePRINT();
bool syntacticParsePROJECTION();
bool syntacticParseRENAME();
bool syntacticParseSELECTION();
bool syntacticParseSORT();

