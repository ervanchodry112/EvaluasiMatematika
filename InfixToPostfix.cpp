#include <bits/stdc++.h>
using namespace std;

bool isOperator(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '%'){
        return true;
    }else{
        return false;
    }
}

vector <string> infix;
string temp;
vector <string>::iterator itr;

void input(){
    string str;
    char ch;
    while(cin.get(ch)){
        if(ch == '\n'){
            break;
        }
        if(ch != ' '){
            str.push_back(ch);
        }
    }
    int length = str.length();

    for(int i = 0; i < length; i++){
        if(str[i] == '(' || str[i] == ')'){
            if(temp.length() != 0){
                infix.push_back(temp);
                temp.clear();
            }
            infix.push_back(str.substr(i, 1));
        }
        if(isdigit(str[i]) || (str[i] == '-' && i == 0 && isdigit(str[i+1]))){
            temp.push_back(str[i]);
            continue;
        }
        if(isOperator(str[i])){
            if(temp.length() != 0){
                infix.push_back(temp);
                temp.clear();
            }
            if((str[i] == '-' && isOperator(str[i-1])) || (str[i] == '-' && i == 0 && str[i+1] == '(') || (str[i] == '-' && str[i-1] == '(')){
                infix.push_back("-1");
                infix.push_back("*");
            }else{
                infix.push_back(str.substr(i, 1));
            }
        }
    }
    if(temp.length() != 0){
        infix.push_back(temp);
        temp.clear();
    }
}

int main(){
    input();
    for(itr = infix.begin(); itr != infix.end() ; itr++){
        cout << *itr << " ";
    }
}
