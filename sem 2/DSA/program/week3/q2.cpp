//Solving problems using Recursion: Factorial of a given number
//Saket Raj
//230970079
//22-01-2024
#include<iostream>
using namespace std;
int Fact(int n){
        if(n==0)
                return 1;
        return n * Fact(n-1);
}
int main(){
        int n;
        cout<<"enter the number to find the factorial: ";
        cin>>n;

        cout<<"factorial of "<<n<<" is "<<Fact(n)<<endl;
        return 0;
}