//Solving problems using Recursion: GCD of 2 numbers
//Saket Raj
//230970079
//22-01-2024
#include<iostream>
using namespace std;
int gcd(int n1, int n2){
        if(n2 != 0)
                return gcd(n2, n1%n2);
        else
                return n1;
}
int main(){
        int num1, num2;
        cout<<"enter number1: ";
        cin>>num1;
        cout<<"enter number2: ";
        cin>>num2;

        cout<<"gcd of "<<num1<<" and "<<num2<<" is "<<gcd(num1, num2)<<endl;
        return 0;
}