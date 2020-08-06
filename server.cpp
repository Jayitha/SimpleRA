//Server Code
#include"parser.h"

using namespace std;

int main(void){

    vector<string> tokenizedCommand;
    regex delim("[^\\s.,]+");
    string command;

    while(1){
        cout<<"\n> ";
        tokenizedCommand.clear();
        while(1){
            getline(cin, command);

            if(command == ";")
                break;
            auto words_begin = std::sregex_iterator(command.begin(), command.end(), delim);
            auto words_end = std::sregex_iterator();

            for (std::sregex_iterator i = words_begin; i != words_end; ++i)
                tokenizedCommand.emplace_back((*i).str());
            
            if(tokenizedCommand.rbegin()->back() == ';'){
                tokenizedCommand.rbegin()->pop_back();
                break;
            }
            cout<<"  ";
        }

        if(tokenizedCommand.size() == 1 && tokenizedCommand.front() == "QUIT"){
            break;
        }

        if(tokenizedCommand.empty()){
            continue;
        }

        parseCommand(tokenizedCommand);
    }
}