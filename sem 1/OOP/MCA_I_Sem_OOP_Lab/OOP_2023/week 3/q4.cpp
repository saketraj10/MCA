//Program to computes the inverse of an integer and the double of the inverse
//Name: Saket Raj
//Reg No: 230970079
//Date: 31-08-2023
#include<iostream>
using namespace std;

int inverse(int n)
{
        int digit,rev=0;
        while(n>0)
        {
                digit = n % 10;
                rev = rev * 10 +digit;
                n=n/10;
        }
        return rev;
}

int calc_double(int n)
{
        return n * 2;
}

int main()
{
        int number;
        cout<<"enter a number: "<<endl;
        cin>>number;
        cout<<"inverse of number: "<<number<<" is : "<<inverse(number)<<endl;
        cout<<"double of inverse is: "<<calc_double(inverse(number))<<endl;
        return 0;
}