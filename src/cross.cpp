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

    Table table1 = tableCatalogue.getTable(parsedQuery.crossFirstRelationName);
    Table table2 = tableCatalogue.getTable(parsedQuery.crossSecondRelationName);

    vector<string> columns;

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

    Table resultantTable(parsedQuery.crossResultRelationName, columns);

    Cursor cursor1 = table1.getCursor();
    Cursor cursor2 = table2.getCursor();

    vector<int> row1 = table1.getNext(cursor1);
    vector<int> row2;
    vector<int> resultantRow;
    resultantRow.reserve(resultantTable.columnCount);

    while (!row1.empty())
    {

        cursor2 = table2.getCursor();
        row2 = table2.getNext(cursor2);
        while (!row2.empty())
        {
            resultantRow = row1;
            resultantRow.insert(resultantRow.end(), row1.begin(), row1.end());
            resultantTable.writeRow(resultantRow);
            row2 = table2.getNext(cursor2);
        }
        row1 = table1.getNext(cursor1);
    }
    return;
}