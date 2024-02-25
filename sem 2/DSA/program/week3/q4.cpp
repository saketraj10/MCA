//Solving problems using Recursion: Fibonacci series upto nth term
//Saket Raj
//230970079
//22-01-2024
#include<iostream>
using namespace std;
int fibonacci(int n){
        if(n==0 || n==1)
                return n;
        return fibonacci(n-1) + fibonacci(n-2);
}
int main(){
        int n;
        cout<<"enter the nth value to display fibonacci series: ";
        cin>>n;

        cout<<"print a fibonacci series: "<<endl;
        for(int i=0; i<n; i++){
                cout<<fibonacci(i)<<" ";
        }
        cout<<endl;
        return 0;
}