#include"parser.h"

using namespace std;

void parseCommand(vector<string> command){

    string commandType = command.front();

    if(commandType == "SELECT"){
        parseSELECT(command);
        return;
    } else if(commandType == "LOAD"){
        parseLOAD(command);
        return;
    } else if(commandType == "INDEX"){
        parseINDEX(command);
        return;
    } else {
        cout<<"SYNTAX ERROR"<<endl;
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