#include"column.h"

string Column::getColumnName(){
    return this->columnName;
}

IndexingStrategy Column::getIndexingStrategy(){
    return this->indexingStrategy;
}