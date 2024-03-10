//Evaluation of Postfix expression
//Saket Raj
//230970079
//12-02-2023
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class Stack{
        private:
        int count;
        int size;
        int* arr;
        public:
        Stack(int n){
                size = n;
                count = 0;
                arr = new int[size];
        }
        bool isFull(){
                if(count==size)
                        return true;
                else
                        return false;
        }
        void push(int data){
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
        int top(){
            return arr[count-1];
        }

};
bool isNumericDigit(char c){
    if(c>='0' && c<='9') return true;
    return false;
}

bool isOperator(char c){
    if(c=='+'|| c=='-'||c=='*'||c=='/'||c=='^')
        return true;
    return false;
}

int performOperation(char op, int operand1, int operand2){
    if(op=='+') return operand1+operand2;
    else if(op=='-') return operand1-operand2;
    else if(op=='*') return operand1*operand2;
    else if(op=='/') return operand1/operand2;
    else if(op=='^') return pow(operand1,operand2);

    else cout<<"something went wrong";
    return -1;
}

int evaluatePostfix(char exp[], int n){
    Stack s(n);
    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i]==' ' || exp[i]==',') continue;
        else if(isOperator(exp[i])){
            int operand2 = s.top(); 
            s.pop();
            int operand1 = s.top();
            s.pop();
            int result = performOperation(exp[i], operand1, operand2);
            s.push(result);
        }
        else if(isNumericDigit(exp[i])){
            int operand = 0;
            while(exp[i]!='\0' && isNumericDigit(exp[i])){
                operand = (operand*10) + (exp[i]-'0');
                i++;
            }
            i--;
            s.push(operand);
        }
    }
    return s.top();
}

int main(){
    char postfix[100];
    cout<<"enter a postfix expression: ";
    cin.get(postfix, 100);
    int n = strlen(postfix);
    cout<<"result: "<<evaluatePostfix(postfix, n)<<endl;
    return 0;
}