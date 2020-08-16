#include "global.h"

/**
 * @brief 
 * SYNTAX: R <- CROSS relation_name relation_name
 */
bool syntacticParseCROSS()
{
    logger.log("syntacticParseCROSS");
    if (tokenizedQuery.size() != 5)
    {
        cout << "SYNTAX ERROR" << endl;
        return false;
    }
    parsedQuery.queryType = CROSS;
    parsedQuery.crossResultRelationName = tokenizedQuery[0];
    parsedQuery.crossFirstRelationName = tokenizedQuery[3];
    parsedQuery.crossSecondRelationName = tokenizedQuery[4];
    return true;
}

bool semanticParseCROSS()
{
    logger.log("semanticParseCROSS");
    if (tableCatalogue.isTable(parsedQuery.crossResultRelationName))
    {
        cout << "SEMANTIC ERROR: Resultant relation already exists" << endl;
        return false;
    }

    if (!tableCatalogue.isTable(parsedQuery.crossFirstRelationName) || !tableCatalogue.isTable(parsedQuery.crossSecondRelationName))
    {
        cout << "SEMANTIC ERROR: Cross relations don't exist" << endl;
        return false;
    }
    return true;
}

void executeCROSS()
{
    logger.log("executeCROSS");

<<<<<<< HEAD
    Table table1 = *(tableCatalogue.getTable(parsedQuery.crossFirstRelationName));
    Table table2 = *(tableCatalogue.getTable(parsedQuery.crossSecondRelationName));

    vector<string> columns;

    if(table1.tableName == table2.tableName){
        parsedQuery.crossFirstRelationName += "1";
        parsedQuery.crossSecondRelationName += "2";
    }

=======
    Table table1 = tableCatalogue.getTable(parsedQuery.crossFirstRelationName);
    Table table2 = tableCatalogue.getTable(parsedQuery.crossSecondRelationName);

    vector<string> columns;

>>>>>>> a6d0881855ea5e395a8c9a64389b8e98b8db445a
    for (int columnCounter = 0; columnCounter < table1.columnCount; columnCounter++)
    {
        string columnName = table1.columns[columnCounter];
        if (table2.isColumn(columnName))
        {
            columnName = parsedQuery.crossFirstRelationName + "_" + columnName;
        }
        columns.emplace_back(columnName);
    }

    for (int columnCounter = 0; columnCounter < table2.columnCount; columnCounter++)
    {
        string columnName = table2.columns[columnCounter];
        if (table1.isColumn(columnName))
        {
            columnName = parsedQuery.crossSecondRelationName + "_" + columnName;
        }
        columns.emplace_back(columnName);
    }

<<<<<<< HEAD
    Table *resultantTable = new Table(parsedQuery.crossResultRelationName, columns);\

    resultantTable->writeRow<string>(columns);
=======
    Table resultantTable(parsedQuery.crossResultRelationName, columns);
>>>>>>> a6d0881855ea5e395a8c9a64389b8e98b8db445a

    Cursor cursor1 = table1.getCursor();
    Cursor cursor2 = table2.getCursor();

    vector<int> row1 = table1.getNext(cursor1);
    vector<int> row2;
    vector<int> resultantRow;
<<<<<<< HEAD
    resultantRow.reserve(resultantTable->columnCount);
=======
    resultantRow.reserve(resultantTable.columnCount);
>>>>>>> a6d0881855ea5e395a8c9a64389b8e98b8db445a

    while (!row1.empty())
    {

        cursor2 = table2.getCursor();
        row2 = table2.getNext(cursor2);
        while (!row2.empty())
        {
            resultantRow = row1;
<<<<<<< HEAD
            resultantRow.insert(resultantRow.end(), row2.begin(), row2.end());
            resultantTable->writeRow<int>(resultantRow);
=======
            resultantRow.insert(resultantRow.end(), row1.begin(), row1.end());
            resultantTable.writeRow<int>(resultantRow);
>>>>>>> a6d0881855ea5e395a8c9a64389b8e98b8db445a
            row2 = table2.getNext(cursor2);
        }
        row1 = table1.getNext(cursor1);
    }
<<<<<<< HEAD
    resultantTable->blockify();
    tableCatalogue.insertTable(resultantTable);
=======
>>>>>>> a6d0881855ea5e395a8c9a64389b8e98b8db445a
    return;
}