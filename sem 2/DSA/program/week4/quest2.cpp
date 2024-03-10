//Conversion of Infix expression to Postfix expression (using stack)  
//Saket Raj
//230970079
//05-02-2024
#include<iostream>
#include<cstring>
using namespace std;
class Stack{
        private:
        int count;
        int size;
        char* arr;
        public:
        Stack(int n){
                size = n;
                count = 0;
                arr = new char[size];
        }
        bool isFull(){
                if(count==size)
                        return true;
                else
                        return false;
        }
        void push(char data){
                if(isFull())
                        cout<<"Stack is full, overflow"<<endl;
                else
                        arr[count++] = data;
        }

        bool empty(){
                if(count==0)
                        return true;
                else
                        return false;
        }
	    void pop(){
            if(empty())
                    cout<<"Stack is empty, underflow"<<endl;
            else{
                    count--;
                }
        }
        char top(){
            return arr[count-1];
        }

};
bool isOperand(char c){
    return (c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0' && c<='9');
}

int precedence(char op){
    if(op == '+' || op =='-') return 1;
    if(op == '*' || op =='/') return 2;
    if(op == '^') return 3;
    return 0;
}

void infixToPost(char infix[], char postfix[], int n){
    Stack s(n+1);
    int j = 0;
    for(int i=0; infix[i]!='\0'; i++){
        if(infix[i]==' ') continue;
        if(isOperand(infix[i])){
            postfix[j++] = infix[i];
        }
        else if(infix[i]=='('){
            s.push(infix[i]);
        }
        else if(infix[i]==')'){
            while(!s.empty() && s.top()!='('){
                postfix[j++] = s.top();
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
        postfix[j++] = s.top();
        s.pop();
    }
    postfix[j] = '\0';
}
int main(){

    char infix[100];
    cout<<"Enter infix expression: ";
    cin.get(infix, 100);
    int n = strlen(infix);
    char postfix[n+1];

    infixToPost(infix, postfix, n);
    cout<<postfix<<endl;
    
    return 0;
}