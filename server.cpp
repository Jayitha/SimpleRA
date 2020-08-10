//Server Code
#include"executor.h"


using namespace std;

void doCommand(){
    if(syntacticParse() && semanticParse())
        executeCommand();
    return;
}

int main(void){

    regex delim("[^\\s.,]+");
    string command;

    while(1){
        cout<<"\n> ";
        tokenizedQuery.clear();
        parsedQuery.clear();
        getline(cin, command);
        auto words_begin = std::sregex_iterator(command.begin(), command.end(), delim);
        auto words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i)
            tokenizedQuery.emplace_back((*i).str());

        if(tokenizedQuery.size() == 1 && tokenizedQuery.front() == "QUIT"){
            break;
        }

        if(tokenizedQuery.empty()){
            continue;
        }

        if(tokenizedQuery.size() == 1){
            cout<<"SYNTAX ERROR"<<endl;
        }

        doCommand();
    }
}