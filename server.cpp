//Server Code
#include"executor.h"


using namespace std;

void doCommand(vector<string> tokenizedCommand);

void doCommand(vector<string> tokenizedCommand){
    parsedQuery.clear();
    parseCommand(tokenizedCommand);
    executeCommand();
    return;
}

int main(void){

    vector<string> tokenizedCommand;
    regex delim("[^\\s.,]+");
    string command;

    while(1){
        cout<<"\n> ";
        tokenizedCommand.clear();
        getline(cin, command);
        auto words_begin = std::sregex_iterator(command.begin(), command.end(), delim);
        auto words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i)
            tokenizedCommand.emplace_back((*i).str());

        if(tokenizedCommand.size() == 1 && tokenizedCommand.front() == "QUIT"){
            break;
        }

        if(tokenizedCommand.empty()){
            continue;
        }

        if(tokenizedCommand.size() == 1){
            cout<<"SYNTAX ERROR"<<endl;
        }

        doCommand(tokenizedCommand);
    }
}