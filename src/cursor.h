#include"bufferManager.h"

class Cursor{
    public:
    Page page;
    int pageIndex;
    string tableName;
    int pagePointer;

    public:
    Cursor(string tableName, int pageIndex);
    vector<int> getNext();
    void nextPage(int pageIndex);
};