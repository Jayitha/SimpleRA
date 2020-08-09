#include"table.h"

Table::Table(string tableName = ""){
    this->tableName = tableName;
    this->columns.clear();
    this->load();
}

void Table::load(string tableName = ""){
    if(tableName == "")
        return;
    tableIndex[this->tableName] = *this;
    //TODO: Write code to load
}


string Table::getTableName(){
    return this->tableName;
}

vector<Column> Table::getColumns(){
    return this->columns;
}


bool Table::isColumn(string columnName){
    for(auto col: this->columns){
        if(col.getColumnName() == columnName){
            return true;
        }
    }
    return false;
}

//Returns column only if it exists
Column Table::getColumn(string columnName){
    for(auto col: this->columns){
        if(col.getColumnName() == columnName){
            return col;
        }
    }
    return;
}

Table::~Table(){
    tableIndex.erase(this->getTableName());
}