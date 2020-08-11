//Server Code
#include"executor.h"


using namespace std;

ParsedQuery parsedQuery;
vector<string> tokenizedQuery;
unordered_map<string, Table> tableIndex;
ofstream logger;

void doCommand(){
    logger<<"doCommand"<<endl;
    if(syntacticParse() && semanticParse())
        executeCommand();
    return;
}

int main(void){

    regex delim("[^\\s.,]+");
    string command;
    logger.open("log", ios::out);

    while(1){
        logger<<"\nReading New Command: ";
        cout<<"\n> ";
        tokenizedQuery.clear();
        parsedQuery.clear();
        getline(cin, command);
        logger<<command<<endl;
        auto words_begin = std::sregex_iterator(command.begin(), command.end(), delim);
        auto words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i){
            tokenizedQuery.emplace_back((*i).str());
            cout<<(*i).str()<<endl;
        }

        if(tokenizedQuery.size() == 1 && tokenizedQuery.front() == "QUIT"){
            break;
        }

        if(tokenizedQuery.empty()){
            continue;
        }

        if(tokenizedQuery.size() == 1){
            cout<<"SYNTAX ERROR"<<endl;
            continue;
        }

        doCommand();
    }
}