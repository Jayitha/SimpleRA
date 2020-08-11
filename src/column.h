#include<iostream>
#include<bits/stdc++.h>
#include<sys/stat.h> 
#include<fstream>

using namespace std;

enum IndexingStrategy{
    BTREE,
    HASH,
    NOTHING
};

class Column{

    public:
    
    string columnName = "";
    IndexingStrategy indexingStrategy = NOTHING;

    Column(string columnName);
};

extern ofstream logger;
void printRowCount(int rowCount);
