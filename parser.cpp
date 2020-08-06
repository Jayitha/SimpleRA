#include"parser.h"

using namespace std;

void parseCommand(vector<string> command){

    string possibleQueryType = command.front();

    if(possibleQueryType == "PRINT"){
        queryType = PRINT;
    } else if(possibleQueryType == "INDEX"){
        queryType = INDEX;
    } else if(possibleQueryType == "LOAD"){
        queryType = LOAD;
    } else if(possibleQueryType == "CLEAR"){
        queryType = CLEAR;
    } else {
        string newRelationName = command.front();
        command.erase(command.begin());
        if(command.front()!="<-"){
            cout<<"SYNTAX ERROR"<<endl;
            return;
        }
        command.erase(command.begin());
        possibleQueryType = command.front();

        if(possibleQueryType == "SELECT"){
            queryType = SELECTION;
        } else if(possibleQueryType == "")
    }
}

void parseSELECT(vector<string> command){
    return;
}

void parseLOAD(vector<string> command){
    return;
}

void parseINDEX(vector<string> command){
    return;
}