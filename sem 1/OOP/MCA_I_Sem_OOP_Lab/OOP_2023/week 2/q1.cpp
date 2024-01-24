//Program to print the patterns
//Name: Saket Raj
//Reg No: 230970079
//Date: 18-08-2023
#include<iostream>
using namespace std;
int main(){
        int n;
        cout<<"Enter any integer value: "<<endl;
        cin>>n;

        for(int i=0; i<n; i++){
                for(int j=i; j<n; j++){
                        cout<<"* ";
                }
                cout<<endl;
        }
        cout<<endl;


        for(int i=1; i<=n; i++){
                for(int j=1; j<=n-i+1; j++){
                        cout<<char(j+64);
                }
                cout<<endl;
        }
        cout<<endl;

	 int a =1;
        for(int i=1; i<=n; i++){
                for(int j=1; j<=i; j++){
                        cout<<a;
                        a++;
                }
                cout<<endl;
        }
        return 0;
}