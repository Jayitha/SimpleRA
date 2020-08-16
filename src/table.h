#include "cursor.h"

enum IndexingStrategy
{
    BTREE,
    HASH,
    NOTHING
};

/**
 * @brief The Table class holds all information related to a loaded table. It
 * also implements methods that interact with the parsers, executors, cursors
 * and the buffer manager. There are typically 2 ways a table object gets
 * created through the course of the workflow - the first is by using the LOAD
 * command and the second is to use assignment statements (SELECT, PROJECT,
 * JOIN, SORT, CROSS and DISTINCT). 
 *
 */
class Table
{
public:
    string sourceFileName = "";
    string tableName = "";
    vector<string> columns;
    vector<uint> distinctValuesPerColumnCount;
    uint columnCount = 0;
    long long int rowCount = 0;
    uint blockCount = 0;
    uint maxRowsPerBlock = 0;
    vector<uint> rowsPerBlockCount;
    bool indexed = false;
    IndexingStrategy indexingStrategy = NOTHING;
    vector<unordered_set<int>> distinctValuesInColumns;
    static ofstream fout;

    bool extractColumnNames(string firstLine);
    bool blockify();
    void updateStatistics(vector<int> row);
    Table();
    Table(string tableName);
    Table(string tableName, vector<string> columns);
    bool load();
    void initializeWriting();
    bool isColumn(string columnName);
    void renameColumn(string fromColumnName, string toColumnName);
    void print();
    ~Table();
    template <typename T>
    void writeRow(vector<T> row, ostream &fout);
    template <typename T>
    void writeRow(vector<T> row);
    void initializeWriting();
    void terminateWriting();
    void makePermanent();
    bool isPermanent();
    vector<int> getNext(Cursor cursor);
    Cursor getCursor();
    int getColumnIndex(string columnName);
};