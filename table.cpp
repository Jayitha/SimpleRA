#include"table.h"

Table::Table(string tableName = ""){
    logger<<"Table::Table"<<endl;
    this->tableName = tableName;
    this->columns.clear();
    this->load();
}

void Table::load(){
    logger<<"Table::load"<<endl;
    if(this->tableName == "")
        return;
    tableIndex[this->tableName] = *this;
    //TODO: Write code to load
}


bool Table::isColumn(string columnName){
    logger<<"Table::icColumn"<<endl;
    for(auto col: this->columns){
        if(col.columnName == columnName){
            return true;
        }
    }
    return false;
}

//Returns column only if it exists
Column Table::getColumn(string columnName){
    logger<<"Table::getColumn"<<endl;
    for(auto col: this->columns){
        if(col.columnName == columnName){
            return col;
        }
    }
}

Table::~Table(){
    logger<<"Table::~Table"<<endl;
    tableIndex.erase(this->tableName);
}