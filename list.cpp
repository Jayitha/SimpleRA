#include"executor.h"

void listTables(){
    cout<<"\nRELATIONS"<<endl;
    cout<<"___________"<<endl;

    int rowCount = 0;
    for(auto rel: tableIndex){
        cout<<rel.first<<endl;
        rowCount++;
    }
    printRowCount(rowCount);
}