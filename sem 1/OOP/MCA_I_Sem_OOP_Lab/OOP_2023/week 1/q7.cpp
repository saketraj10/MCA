//Program to calculate the compound interest
//Name: Saket Raj
//Reg No: 230970079
//Date: 16-08-2023
#include<iostream>
#include<cmath>
using namespace std;
int main(){
        float a, p, r, n, t;

        cout<<"Enter the principal amount: "<<endl;
        cin>>p;

        cout<<"Enter the rates: "<<endl;
        cin>>r;

        cout<<"Enter the no of times that interest is compound  per unit time: "<<endl;
        cin>>n;

        cout<<"Enter the time: "<<endl;
        cin>>t;

        a = p * pow(1+(r/(100*n)),n*t);

        cout<<"Compound interest: "<<a<<endl;

        return 0;
}

output

Enter the principal amount:
5500
Enter the rates:
3
Enter the no of times that interest is compound  per unit time:
5
Enter the time:
5
Compound interest: 6387.23