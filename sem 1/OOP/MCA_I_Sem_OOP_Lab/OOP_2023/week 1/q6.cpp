//Program to convert the temperature given in fahrenheit to celsius and vice versa
//Name: Saket Raj
//Reg No: 230970079
//Date: 16-08-2023
#include<iostream>
using namespace std;
int main(){
        float celsius, fahrenheit;

        cout<<"Enter fahrenheit: "<<endl;
        cin>>fahrenheit;

        celsius = (fahrenheit-32) * 5 / 9;

        cout<<"Celsius: "<<celsius<<endl;

        cout<<"Enter celsius: "<<endl;
        cin>>celsius;

        fahrenheit = (9*celsius) / 5 + 32;

        cout<<"Fahrenheit: "<<fahrenheit<<endl;

        return 0;
}