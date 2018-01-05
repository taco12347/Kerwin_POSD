#include "parser.h"
#include "scanner.h"
#include <iostream>

using namespace std;

int main(){
    string keyIn;
    string content = "";
    Parser *parser;
    while(1){
        while(1){
            if(content == ""){
                cout << "?- ";
            }
            else{
                cout << "|   ";
            }
            getline(cin, keyIn);
            if(keyIn != ""){
                while(keyIn[0] == ' ')
                    keyIn = keyIn.substr(1, keyIn.size() - 1);
            }
            content += keyIn;
            if(keyIn == "" || content.back() == '.'){
                break;
            }
            else continue;
        }
        if(content == "halt.") break;
        parser = new Parser(Scanner(content));
        try{
            parser->buildExpression();
            cout << parser->expressionTree()->getDiscription() << endl;
        }catch(string error){
            cout << error << endl;
        }
        content = "";
    }
}