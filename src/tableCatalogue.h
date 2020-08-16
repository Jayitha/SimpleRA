#include "table.h"

/**
 * @brief The TableCatalogue acts like an index of tables existing in the
 * system. Everytime a table is added(removed) to(from) the system, it needs to
 * be added(removed) to(from) the tableCatalogue. The constructor is private
 * indicating that no object of this class can be created, instead all members
 * of the class are static. 
 *
 */
class TableCatalogue
{

    unordered_map<string, Table> tables;

public:
    TableCatalogue() {}
    void insertTable(Table table);
    void deleteTable(string tableName);
    Table getTable(string tableName);
    bool isTable(string tableName);
    bool isColumnFromTable(string columnName, string tableName);
    void print();
};