//Program to find the largest of three numbers
//Name: Saket Raj
//Reg No: 230970079
//Date: 11-08-2023
#include<iostream>
using namespace std;
int main(){
        int first_num, second_num, third_num;

        cout<<"Enter the first num: "<<endl;
        cin>>first_num;

        cout<<"Enter the second num: "<<endl;
        cin>>second_num;

        cout<<"Enter the third num: "<<endl;
        cin>>third_num;

        if(first_num > second_num){
                if(first_num > third_num){
                        cout<<"first num is greatest"<<endl;
                }
                else{
                        cout<<"third num is greatest"<<endl;
                }
        }
	else{
                if(second_num > third_num){
                        cout<<"second num is greatest"<<endl;
                }
                else{
                        cout<<"third num is greatest"<<endl;
                }
        }
        return 0;
}