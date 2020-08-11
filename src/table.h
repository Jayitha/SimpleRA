#include"column.h"

class Table{

    public:

    string tableName;
    string sourceFileName;
    vector<Column> columns;

    Table(string tableName);
    void load();
    bool isColumn(string columnName);
    Column getColumn(string columnName);
    ~Table();
};

extern unordered_map<string, Table> tableIndex;

bool isTable(string relationName);
Table getTable(string tableName);
bool isColumnFromTable(string columnName, string relationName);
bool isFileExists(string relationName);