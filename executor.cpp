#include"executor.h"

void executeCommand(){

    switch(parsedQuery.queryType){
        case CLEAR: clear(); break;
        case CROSS: cross(); break;
        case DISTINCT: distinct(); break;
        case INDEX: index(); break;
        case LIST: listTables(); break;
        case LOAD: load(); break;
        case PRINT: print(); break;
        case PROJECTION: projection(); break;
        case RENAME: rename(); break;
        case SELECTION: selection(); break;
        case SORT: sort(); break;
        default: cout<<"PARSING ERROR"<<endl;
    }

    return;
}

void printRowCount(int rowCount){
    cout<<"\n\nRow Count: "<<rowCount<<endl;
    return;
}