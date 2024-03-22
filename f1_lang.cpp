/*
    Parser for f1-lang

    For now, it just replaces keywords to work it C++ syntax

*/
#include <bits/stdc++.h>

using namespace std;

void createMap(unordered_map<string, string> &mp){
    mp["through_goes"] = "return";
    mp["lights_off"] = "main";
    mp["POLE"] = "false";
    mp["DNF"] = "true";
    mp["drs"] = "while";
    mp["push"] = "if";
    mp["maintain"] = "else";
    mp["pit"] = "break";
    mp["teamRadio"] = "printf";

}

bool checkEnds(char a){
    switch(a){
        case '(':
        case ')':
        case ';':
        case '/':
        case '.':
        case '-':
        case '*':
        case ' ':
            return true;
    }

    return false;
}

string parseWords(string str, unordered_map<string, string> &mp){
    string ret = "", temp = "";
    bool isOpenQuote = false;
    int l = 0, r = 0;

    for(int i = 0; i < str.size(); i++){
        if(str[i] == '\"' || str[i] == '\'') isOpenQuote = !isOpenQuote;
        
        if(!checkEnds(str[i])){
            temp += str[i];
        } else {
            if(mp.find(temp) != mp.end()) ret += mp[temp] + str[i];
            else ret += temp + str[i];
            temp = "";
        }
    }

    if(temp != ""){
        if(mp.find(temp) != mp.end()) ret += mp[temp];
        else ret += temp;
    }
    
    return ret;
}


int main(int argc, char *argv[]){
    if(argc < 2){
        cout<<"\n Invalid argument. \n Run the program as f1_lang <PATH TO FILE>\n";
        return 1;
    }

    char * filepath = argv[1];

    ifstream input;
    ofstream output;

    input.open(filepath);
    output.open("output.cpp");

    if(!input.is_open()){
        cout<<"\n Error opening input file\n";
        exit(1);
    } else if(!output.is_open()){
        cout<<"\n Error opening output file\n";
        exit(1);
    }

    unordered_map<string, string> reservedWords;
    createMap(reservedWords);

    string text = "";
    int l = 0, r = 1;

    while(getline(input, text)){
        //cout<<text<<endl;
        text = parseWords(text, reservedWords);
        //cout<<text<<endl;

        output << text <<endl;
    }

    input.close();
    output.close();

    return 0;
}