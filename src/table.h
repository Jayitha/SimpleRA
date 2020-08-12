#include"column.h"

class Table{

    public:

    string tableName = "";
    string sourceFileName = "";
    vector<Column> columns;
    long long int rowCount = -1;
    fstream filePointer;
    unordered_map<string, int> row;

    Table();
    Table(string tableName);
    bool load();
    bool isColumn(string columnName);
    Column getColumn(string columnName);
    void renameColumn(string fromColumnName, string toColumnName);
    void print();
    void initializeCursor();
    bool getNext();
    void writeToSourceFile();
    void closeFilePointer();
    ~Table();
};

extern unordered_map<string, Table*> tableIndex;

bool isTable(string relationName);
Table* getTable(string tableName);
bool isColumnFromTable(string columnName, string relationName);
bool isFileExists(string relationName);
Table *createNewTable(string relationName, vector<Column> columns);