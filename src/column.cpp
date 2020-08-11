#include"column.h"

Column::Column(string columnName){
    this->columnName = columnName;
    this->indexingStrategy = NOTHING;
}