//Program to implement the solution to change making problem
//Name: Saket Raj
//Reg No: 230970079
//Date: 25-08-2023
#include<iostream>
using namespace std;
int main(){
        int total_bill, cash_paid, balance;

        cout<<"Enter the total bill: "<<endl;
        cin>>total_bill;
        cout<<"Enter the cash paid: "<<endl;
        cin>>cash_paid;

        balance = cash_paid - total_bill;

        cout<<"Balance: "<<balance<<endl;
        int note[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        while(balance>0){
                for(int i=0; i<10; i++){
                        if(note[i]<=balance){
                                cout<<"$ " <<note[i]<<" ";
                                balance -= note[i];
                                break;
                        }
                }
        }
        return 0;
}