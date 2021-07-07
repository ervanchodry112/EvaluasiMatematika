#include <bits/stdc++.h>
using namespace std;
#define MAKS_SIZE 101

class Stack{
public:
    int top = -1;
    char operasi[MAKS_SIZE];

    bool isEmpty(){
        return top == -1;
    }
    bool isFull(){
        return top == (MAKS_SIZE-1);
    }
    void push(char x){
        if(isFull()){
            cout << "Stack Penuh" << endl;
        }
        else{
            operasi[++top] = x;
        }
    }
    char pop(){
        if(isEmpty()){
            cout << "Stack Kosong" << endl;
            return 0;
        }
        else{
            int temp = operasi[top--];
            return temp;
        }
    }
    void print(){
        for(int i = 0; i <= top; i++){
            cout << operasi[i] << " ";
        }
        cout << "\n";
    }
};

Stack infix;
Stack postfix;

bool isOperand(char x){
    if(x == '1' || x == '2' || x == '3' || x == '4' || x == '5' ||
        x == '6' || x == '7' || x == '8' || x == '9' ||x == '0'){
        return true;
    }
    else{
        return false;
    }
}

bool isOperator(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '%'){
        return true;
    }else{
        return false;
    }
}

int precendence(char x){
    if(x == '+' || x == '-'){
        return 1;
    }
    if(x == '*' || x == '/'){
        return 2;
    }
    return 0;
}

bool bigOne(char x, char y){
    int xValue, yValue;
    xValue = precendence(x);
    yValue = precendence(y);
    return xValue <= yValue;
}

void input(){
    char forInfix[MAKS_SIZE];
    cin.ignore(0, '\n');
    cin.getline(forInfix, 100);
    int i = -1;
    
    while(forInfix[++i] != '\0'){       
        
        
        // if((forInfix[i] == '-' && isOperator(forInfix[i-1])) || (forInfix[i] == '-' && i == 0)){
        //     if(isOperand(forInfix[i+1])){
        //         i++;
        //         cout << forInfix[i-1] << forInfix[i];
        //         if(isOperand(i+1)){
        //             cout << forInfix[i+1] << " ";
        //             i++;
        //         }else{
        //             cout << " ";
        //             i++;
        //         }
        //     }else{
        //         cout << "-1 * ";
        //         i++;
        //     }
        // }
        // if(isOperand(forInfix[i]) && isOperand(forInfix[i+1])){
        //     cout << forInfix[i] << forInfix[i+1] << " ";
        //     i++;
        //     i++;
        // }
        // if(isOperand(forInfix[i]) && isOperand(forInfix[i-1])){
        //     cout << forInfix[i] << " ";
        //     i++;
        // }
        // Untuk menghilangkan spasi
        if(forInfix[i] == ' '){
            for(int j = i; forInfix[j] != '\0'; j++){
                forInfix[j] = forInfix[j+1];
            }
            cout << forInfix[i] << " ";
        }
        else{
            cout << forInfix[i] << " ";
        }
        infix.push(forInfix[i]);
    }
}

int main(){
    input();

    return 0;
}