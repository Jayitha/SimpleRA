#include<iostream>
#include<bits/stdc++.h>

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