#include"table.h"

Table::Table(string tableName = ""){
    logger<<"Table::Table"<<endl;
    this->tableName = tableName;
    this->sourceFileName = "../data/"+tableName+".csv";
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

bool isTable(string relationName){
    for(auto rel: tableIndex){
        if(rel.first == relationName)
            return true;
    }
    return false;
}

Table getTable(string relationName){
    for(auto rel:tableIndex){
        if(rel.first == relationName)
            return rel.second;
    }
}

bool isColumnFromTable(string columnName, string relationName){
    Table rel = getTable(relationName);
    if(rel.isColumn(columnName))
        return true;
    return false;
}

bool isFileExists(string relationName){
    string fileName = "../data/"+relationName+".csv";
    struct stat buffer;
    return (stat (fileName.c_str(), &buffer) == 0); 
}