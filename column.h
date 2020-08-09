#include<iostream>
#include<bits/stdc++.h>

using namespace std;

enum IndexingStrategy{
    BTREE,
    HASH,
    NOTHING
};

class Column{

    string columnName;
    IndexingStrategy indexingStrategy;

    public:
    
    string getColumnName();
    IndexingStrategy getIndexingStrategy();
};