#include"column.h"

class Table{
    
    string tableName;
    vector<Column> columns;

    public:

    Table(string tableName);
    void load(string tableName);
    string getTableName(void);
    vector<Column> getColumns();
    bool isColumn(string columnName);
    Column getColumn(string columnName);
    ~Table();
};

extern unordered_map<string, Table> tableIndex;