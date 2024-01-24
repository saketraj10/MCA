//Program to exchange two number without using temporary variable
//Name: Saket Raj
//Reg No: 230970079
//Date: 11-08-2023
#include<iostream>
using namespace std;
int main(){
        int first_num, second_num;
        cout<<"Enter the first num: "<<endl;
        cin>>first_num;

        cout<<"Enter the second num: "<<endl;
        cin>>second_num;

        first_num = first_num + second_num;
        second_num = first_num - second_num;
        first_num = first_num - second_num;

        cout<<"First num: "<<first_num<<endl;
        cout<<"Second num: "<<second_num<<endl;

        return 0;
}