#include<iostream>
#include<bits/stdc++.h>
#include<fstream>

using namespace std;

enum IndexingStrategy{
    BTREE,
    HASH,
    NOTHING
};

class Column{

    public:
    
    string columnName;
    IndexingStrategy indexingStrategy;
};

extern ofstream logger;