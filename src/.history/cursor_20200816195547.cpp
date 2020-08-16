#include "global.h"
Cursor::Cursor(string tableName, int pageIndex, string conditionColumnName, BinaryOperator binaryOperator, int conditionValue){
    logger.log("Cursor::Cursor");
    this->page = bufferManager.getPage(tableName, pageIndex);
    this->pagePointer = 0;
    this->tableName = tableName;
    this->pageIndex = pageIndex;
    this->conditionColumnName = conditionColumnName;
    this->binaryOperator = binaryOperator;
    this->conditionValue = conditionValue;
    this->conditionColumnIndex = tableCatalogue.getTable(tableName).getColumnIndex(conditionColumnName);
}

Cursor::Cursor(string tableName, int pageIndex, string conditionColumnName, BinaryOperator binaryOperator, string secondColumnName){
    logger.log("Cursor::Cursor");
    this->page = bufferManager.getPage(tableName, pageIndex);
    this->pagePointer = 0;
    this->tableName = tableName;
    this->pageIndex = pageIndex;
    this->conditionColumnName = conditionColumnName;
    this->binaryOperator = binaryOperator;
    this->conditionValue = conditionValue;
    this->conditionColumnIndex = tableCatalogue.getTable(tableName).getColumnIndex(conditionColumnName);
}

Cursor::Cursor(string tableName, int pageIndex)
{
    logger.log("Cursor::Cursor");
    this->page = bufferManager.getPage(tableName, pageIndex);
    this->pagePointer = 0;
    this->tableName = tableName;
    this->pageIndex = pageIndex;
    this->conditionColumnName = "";
    this->binaryOperator = NO_BINOP_CLAUSE;
    this->conditionValue = 0;
    this->conditionColumnIndex = -1;
}

bool Cursor::evaluateBinOp(int value){
    switch(this->binaryOperator){
        case NO_BINOP_CLAUSE: return true;
        case LESS_THAN: return (value < this->conditionValue);
        case GREATER_THAN: return (value > this->conditionValue);
        case LEQ: return (value <= this->conditionValue);
        case GEQ: return (value >= this->conditionValue);
        case EQUAL: return (value == this->conditionValue);
        case NOT_EQUAL: return (value != this->conditionValue);
        default: return true;
    }
}

vector<int> Cursor::getNext()
{
    logger.log("Cursor::geNext");
    vector<int> result;
    bool evaluation = false;
    result = this->page.getRow(this->pagePointer);
    this->pagePointer++;

    if(!result.empty())
        evaluation = this->evaluateBinOp(result[this->conditionColumnIndex]);

    while(result.empty() || !evaluation){
        if(result.empty()){
            Table table = tableCatalogue.getTable(this->tableName);
            int pageIndex = table.getNextPageIndex(*this);
            if(pageIndex == -1)
                return result;
            this->nextPage(pageIndex);
            result = this->page.getRow(this->pagePointer);
            this->pagePointer++;
        }else if(!evaluation){
            result = this->page.getRow(this->pagePointer);
            this->pagePointer++;
            if(!result.empty())
                evaluation = this->evaluateBinOp(result[this->conditionColumnIndex]);
        }
    }
    return result;
}

void Cursor::nextPage(int pageIndex)
{
    this->page = bufferManager.getPage(this->tableName, pageIndex);
    this->pageIndex = pageIndex;
    this->pagePointer = 0;
}