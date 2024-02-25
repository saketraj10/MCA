//Conversion of Infix expression to Postfix expression (using stack)  
//Saket Raj
//230970079
//05-02-2024
#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isOperand(char c){
    return (c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0' && c<='9');
}

int precedence(char op){
    if(op == '+' || op =='-') return 1;
    if(op == '*' || op =='/') return 2;
    if(op == '^') return 3;
    return 0;
}

string infixToPost(string infix){
    stack<char> s;
    string postfix;
    for(int i=0; i<infix.length(); i++){
        if(isOperand(infix[i])){
            postfix += infix[i];
        }
        else if(infix[i]=='('){
            s.push(infix[i]);
        }
        else if(infix[i]==')'){
            while(!s.empty() && s.top()!='('){
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            while(!s.empty() && precedence(s.top())>=precedence(infix[i])){
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }

    while(!s.empty()){
        postfix += s.top();
        s.pop();
    }
    return postfix;
}
int main(){
    string infix;
    cout<<"Enter infix expression: ";
    cin>>infix;

    cout<<infixToPost(infix)<<endl;
    
    return 0;
}