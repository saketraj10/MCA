//Conversion of Infix expression to Prefix expression (using stack) 
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

string infixToPre(string infix){
    stack<char> s;
    string prefix;
    for(int i=0; i<infix.length(); i++){
        if(isOperand(infix[i])){
            prefix += infix[i];
        }
        else if(infix[i]==')'){
            s.push(infix[i]);
        }
        else if(infix[i]=='('){
            while(!s.empty() && s.top()!=')'){
                prefix += s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            while(!s.empty() && precedence(s.top())>precedence(infix[i])){
                prefix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }

    while(!s.empty()){
        prefix += s.top();
        s.pop();
    }
    return prefix;
}

string rev(string inf){
    string r;
    int n = inf.length();
    for(int i=0; i<=n; i++){
        r += inf[n-i-1];
    }
    return r;
}
int main(){
    string infix;
    cout<<"Enter infix expression: ";
    cin>>infix;

    string in = rev(infix);

    string pre = infixToPre(in);

    string prefix = rev(pre);
    cout<<prefix<<endl;
    
    return 0;
}