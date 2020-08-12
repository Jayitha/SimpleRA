#include"table.h"

Table::Table(string tableName){
    logger<<"Table::Table"<<endl;
    this->tableName = tableName;
    this->sourceFileName = "../data/"+tableName+".csv";
    this->columns.clear();
    this->row.empty();
    this->rowCount = -1;
}

Table::Table(){

}

bool Table::load(){
    logger<<"Table::load"<<endl;
    fstream fin(this->sourceFileName, ios::in);
    vector<string> row;
    string line, word;
    while(getline(fin, line)){
        if(this->rowCount == -1){
            stringstream s(line);  
            while(getline(s, word, ',')) {
                word.erase(std::remove_if(word.begin(), word.end(), ::isspace), word.end()); 
                row.push_back(word); 
                this->row[word] = 0;
            }
            for(auto columnName: row){
                Column col(columnName);
                this->columns.emplace_back(col);
            }
        }
        this->rowCount++;
    }
    fin.close();
    if(this->rowCount == -1){
        return false;
    }
    return true;
}


bool Table::isColumn(string columnName){
    logger<<"Table::isColumn"<<endl;
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

void Table::renameColumn(string fromColumnName, string toColumnName){
    for(int i=0; i<this->columns.size(); i++){
        if(columns[i].columnName == fromColumnName){
            columns[i].columnName = toColumnName;
            this->row.erase(fromColumnName);
            this->row[toColumnName] = 0;
            break;
        }
    }
    return;
}

void Table::print(){
    long long count = min((long long)10, this->rowCount);

    //print headings
    for(int i=0; i<this->columns.size(); i++){
        if(i!=0)
            cout<<", ";
        cout<<this->columns[i].columnName;
    }
    cout<<endl;

    fstream fin(this->sourceFileName.c_str(), ios::in);
    string line;
    getline(fin, line);
    for(int i=0; i < count; i++){
        getline(fin, line);
        cout<<line<<endl;
    }
    fin.close();
    printRowCount(count);
}

void Table::initializeCursor(){
    this->filePointer.open(this->sourceFileName, ios::in);
    string headers;
    getline(filePointer, headers);
    return;
}

bool Table::getNext(){
    string line;
    if(getline(filePointer, line)){
        stringstream s(line);
        string word;
        int ind = 0;
        while(getline(s, word, ',')) {
            word.erase(std::remove_if(word.begin(), word.end(), ::isspace), word.end()); 
            this->row[this->columns[ind].columnName] = stoi(word);
            ind++;
        }
        return true;
    }
    return false;
}

void Table::writeToSourceFile(){
    logger<<"Table::writeToSourceFile"<<endl;
    for(int i=0; i<this->columns.size(); i++){
        if(i!=0)
            filePointer<<", ";
        filePointer<<this->row[this->columns[i].columnName];
    }
    filePointer<<endl;
    this->rowCount++;
}

void Table::closeFilePointer(){
    this->filePointer.close();
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

Table* getTable(string relationName){
    for(auto rel:tableIndex){
        if(rel.first == relationName)
            return rel.second;
    }
}

bool isColumnFromTable(string columnName, string relationName){
    Table *rel = getTable(relationName);
    if(rel->isColumn(columnName))
        return true;
    return false;
}

bool isFileExists(string relationName){
    string fileName = "../data/"+relationName+".csv";
    struct stat buffer;
    return (stat (fileName.c_str(), &buffer) == 0); 
}

Table* createNewTable(string relationName, vector<Column> columns){
    Table *rel = new Table(relationName);
    tableIndex[relationName] = rel;
    rel->columns = columns;
    for(auto col: columns)
        rel->row[col.columnName] = 0;
    rel->filePointer.open(rel->sourceFileName, ios::out);

    for(int i=0; i<columns.size(); i++){
        if(i!=0)
            rel->filePointer<<", ";
        rel->filePointer<<columns[i].columnName;
    }
    rel->filePointer<<endl;
    rel->rowCount++;
    return rel;
}