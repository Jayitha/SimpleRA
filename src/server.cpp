//Server Code
#include"executor.h"

using namespace std;

ParsedQuery parsedQuery;
vector<string> tokenizedQuery;
unordered_map<string, Table*> tableIndex;
ofstream logger;
uint BLOCK_SIZE = 10;


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
        cout<<"\n> ";
        tokenizedQuery.clear();
        parsedQuery.clear();
        logger<<"\nReading New Command: ";
        getline(cin, command);
        logger<<command<<endl;
        
        auto words_begin = std::sregex_iterator(command.begin(), command.end(), delim);
        auto words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i)
            tokenizedQuery.emplace_back((*i).str());

        if(tokenizedQuery.size() == 1 && tokenizedQuery.front() == "QUIT"){
            break;
        }

        if(tokenizedQuery.size() == 2 && tokenizedQuery.front() == "BLOCK_SIZE"){
            BLOCK_SIZE = stoi(tokenizedQuery[1]);
            logger<<"Block size set to: "<<BLOCK_SIZE<<endl;
            continue;
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