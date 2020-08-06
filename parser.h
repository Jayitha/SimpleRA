#include<bits/stdc++.h>
#include<iostream>
using namespace std;

enum QueryType{
    SELECT,
    INDEX,
    LOAD
};

enum IndexingStrategy{
    HASH,
    BTREE,
    NOTHING
};

enum BinaryOperator{
    LESSER_THAN,
    GREATER_THAN,
    EQUAL,
    NOT_EQUAL,
    NA
};

enum WhereClauseType{
    BIN_OP,
    BETWEEN,
    NA
};

enum FromClauseType{
    FROM_LIST,
    JOIN
};

enum OrderStrategy{
    ASC,
    DESC,
    NA
};

class ParsedQuery{
    
    QueryType queryType;

    string loadTableName;

    string indexTableName;
    string columnName;
    IndexingStrategy indexingStrategy;

    vector<pair<string, string>> selectList;
    FromClauseType fromClauseType;
    vector<pair<string, string>> fromList;
    vector<pair<string, string>> joinList;

    WhereClauseType whereClauseType;
    BinaryOperator binaryOperator;
    vector<pair<string, string>> binaryOperatorClauseList;
    pair<string, string> betweenClauseColumn;
    pair<int, int> betweenRange;

    OrderStrategy orderStrategy;
    pair<string, string> orderByColumn;
};

void parseCommand(vector<string>);
void parseSELECT(vector<string>);
void parseLOAD(vector<string>);
void parseINDEX(vector<string>);