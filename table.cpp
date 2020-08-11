#include"table.h"

Table::Table(string tableName = ""){
    this->tableName = tableName;
    this->columns.clear();
    this->load();
}

void Table::load(){
    if(this->tableName == "")
        return;
    tableIndex[this->tableName] = *this;
    //TODO: Write code to load
}


bool Table::isColumn(string columnName){
    for(auto col: this->columns){
        if(col.columnName == columnName){
            return true;
        }
    }
    return false;
}

//Returns column only if it exists
Column Table::getColumn(string columnName){
    for(auto col: this->columns){
        if(col.columnName == columnName){
            return col;
        }
    }
}

Table::~Table(){
    tableIndex.erase(this->tableName);
}