#include"column.h"

class Table{

    public:

    string tableName;
    vector<Column> columns;

    Table(string tableName);
    void load();
    bool isColumn(string columnName);
    Column getColumn(string columnName);
    ~Table();
};

extern unordered_map<string, Table> tableIndex;