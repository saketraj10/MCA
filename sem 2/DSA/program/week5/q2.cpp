//Evaluation of Prefix expression
//Saket Raj
//230970079
//12-02-2024
#include<iostream>
#include<stack>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;

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

int evaluatePrefix(char exp[]){
    stack<int> s;
    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i]==' ' || exp[i]==',') continue;
        else if(isOperator(exp[i])){
            int operand1 = s.top(); 
            s.pop();
            int operand2 = s.top();
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
	    int rev = 0;
            while(operand>0){
            int rem = operand % 10;
            rev = rev*10 + rem;
            operand /= 10;
            }
            s.push(rev);
        }
    }
    return s.top();
}
void rev(char prefix[]){
    int len = strlen(prefix);
    for(int i=0; i<len/2; i++){
        char temp = prefix[i];
        prefix[i] = prefix[len-i-1];
        prefix[len-i-1] = temp;
    }
}
int main(){
    char prefix[100];
    cout<<"enter a prefix expression: ";
    cin.get(prefix, 100);
    rev(prefix);
    cout<<"result: "<<evaluatePrefix(prefix)<<endl;
    return 0;
}