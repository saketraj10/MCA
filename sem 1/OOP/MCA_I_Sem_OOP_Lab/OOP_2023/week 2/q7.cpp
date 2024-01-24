//Program define a structure to represent the bank account of a customer
//Name: Saket Raj
//Reg No: 230970079
//Date: 26-08-2023
#include<iostream>
using namespace std;
struct baccount{
        char name[25], acctype[20];
        int account_no;
        float balance_amount;
} a;
int main(){
        int ch;
        char c;
        cout<<"Enter the customer name: "<<endl;
        cin>>a.name;
        cout<<"Enter the account number: "<<endl;
        cin>>a.account_no;
        cout<<"Enter the account type: "<<endl;
        cin>>a.acctype;
        cout<<"Enter the balance amount: "<<endl;
        cin>>a.balance_amount;
        do{
	
	 cout<<"Enter the choice: "<<endl;

        cout<<"1. Deposit: "<<endl;
        cout<<"2. Withdrawn: "<<endl;
        cin>>ch;

        switch(ch){
                case 1:
                        float damount;
                        cout<<"Enter the amount for deposit: "<<endl;
                        cin>>damount;
                        if(damount>0){
                                a.balance_amount += damount;
                                cout<<"Successful deposited"<<endl;
                                cout<<"Balance: "<<a.balance_amount<<endl;
                        }
                        else{
                                cout<<"Amount must be greater than 0"<<endl;
                        }
                        break;
		 case 2:
                        float wamount;
                        cout<<"Enter the amount for withdrawn: "<<endl;
                        cin>>wamount;
                        if(a.balance_amount > wamount){
                                a.balance_amount -= wamount;
                                cout<<"Successful withdrawn"<<endl;
                                cout<<"Balance: "<<a.balance_amount<<endl;
                        }
                        else{
                                cout<<"Insufficient balance"<<endl;
                        }
                        break;
                default:
                        cout<<"Invalid input"<<endl;
        }
        cout<<"Do you want to continue: "<<endl;
        cin>>c;
        }
        while(c == 'y' || c == 'Y');
        return 0;
}