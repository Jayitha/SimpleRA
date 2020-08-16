#include "global.h"

BufferManager::BufferManager()
{
    logger.log("BufferManager::BufferManager");
}

Page BufferManager::getPage(string tableName, int pageIndex)
{
    logger.log("BufferManager::getPage");
    string pageName = tableName + "_Page" + to_string(pageIndex);
    if (this->inPool(pageName))
        return this->getFromPool(pageName);
    else
        return this->insertIntoPool(tableName, pageIndex);
}

bool BufferManager::inPool(string pageName)
{
    logger.log("BufferManager::inPool");
    for (auto page : this->pages)
    {
        if (pageName == page.pageName)
            return true;
    }
    return false;
}

Page BufferManager::getFromPool(string pageName)
{
    logger.log("BufferManager::getFromPool");
    for (auto page : this->pages)
        if (pageName == page.pageName)
            return page;
}

Page BufferManager::insertIntoPool(string tableName, int pageIndex)
{
    logger.log("BufferManager::insertIntoPool");
    Page page(tableName, pageIndex);
    if (this->pages.size() >= BLOCK_COUNT)
        pages.pop_front();
    pages.push_back(page);
    return page;
}

void BufferManager::writePage(string tableName, int pageIndex, vector<vector<int>> rows, int rowCount)
{
    Page page(tableName, pageIndex, rows, rowCount);
    page.writePage();
}

void BufferManager::deleteFile(string fileName)
{
    if (remove(fileName.c_str()))
        logger.log("BufferManager::deleteFile: Err");
}

void BufferManager::deleteFile(string tableName, int pageIndex)
{
    string fileName = tableName + "_Page" + to_string(pageIndex);
    this->deleteFile(fileName);
}