//Program to convert the time in seconds to hours, minutes and seconds
//Name: Saket Raj
//Reg No: 230970079
//Date: 16-08-2023
#include<iostream>
using namespace std;
int main(){
        int sec, min, hour;

        cout<<"Enter the seconds: "<<endl;
        cin>>sec;

        min = sec * 1/60;
        hour = sec * 1/3600;

        cout<<"Minutes: "<<min<<endl;
        cout<<"Hours: "<<hour<<endl;
        return 0;
}