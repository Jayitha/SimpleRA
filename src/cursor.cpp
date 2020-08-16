#include"global.h"

Cursor::Cursor(string tableName, int pageIndex){
    logger.log("Cursor::Cursor");
    this->page = bufferManager.getPage(tableName, pageIndex);
    this->pagePointer = 0;
    this->tableName = tableName;
    this->pageIndex = pageIndex;
}

vector<int> Cursor::getNext(){
    logger.log("Cursor::geNext");
    vector<int> result = this->page.getRow(this->pagePointer);
    this->pagePointer++;
    return result;
}

void Cursor::nextPage(int pageIndex){
    this->page = bufferManager.getPage(this=>tableName, pageIndex);
    this->pageIndex = pageIndex;
    this->pagePointer = 0;
}