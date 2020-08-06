#include"table.h"

using namespace std;

enum QueryType{
    SELECTION,
    PROJECTION,
    CROSS,
    RENAME,
    DISTINCT,
    SORT,
    INDEX,
    CLEAR,
    LOAD,
    PRINT,
    UNDETERMINED
};

extern QueryType queryType = UNDETERMINED;

void doCommand(vector<string> tokenizedCommand);

