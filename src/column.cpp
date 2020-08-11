#include"column.h"

Column::Column(string columnName){
    this->columnName = columnName;
    this->indexingStrategy = NOTHING;
}

void printRowCount(int rowCount){
    cout<<"\n\nRow Count: "<<rowCount<<endl;
    return;
}