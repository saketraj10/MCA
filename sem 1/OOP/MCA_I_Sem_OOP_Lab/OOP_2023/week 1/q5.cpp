//Program to convert the distance in mm to cm , inch, feet
//Name: Saket Raj
//Reg No: 230970079
//Date: 16-08-2023
#include<iostream>
using namespace std;
int main(){
        float mm, cm, inch, feet;
        cout<<"Enter the value of mm: "<<endl;
        cin>>mm;

        cm = mm * 1/10;
        inch = cm * 1/2.5;
        feet = inch * 1/12;

        cout<<"cm: "<<cm<<endl;
        cout<<"inch: "<<inch<<endl;
        cout<<"feet: "<<feet<<endl;

        return 0;
}