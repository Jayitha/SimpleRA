#include"table.h"

Table::Table(string tableName){
    logger<<"Table::Table"<<endl;
    this->tableName = tableName;
    this->sourceFileName = "../data/"+tableName+".csv";
    this->columns.clear();
    this->rowCount = -1;
}

Table::Table(){

}

bool Table::load(){
    logger<<"Table::load"<<endl;
    fstream fin(this->sourceFileName.c_str(), ios::in);
    vector<string> row;
    string line, word;
    while(getline(fin, line)){
        stringstream s(line);  
        while(getline(s, word, ',')) { 
            row.push_back(word); 
        } 

        if(this->rowCount == -1){
            for(auto columnName: row){
                Column col(columnName);
                this->columns.emplace_back(col);
            }
        }
        this->rowCount++;
    }
    if(this->rowCount == -1){
        return false;
    }
    return true;
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