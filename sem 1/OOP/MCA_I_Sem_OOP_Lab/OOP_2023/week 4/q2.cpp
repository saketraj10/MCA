#include<iostream>
using namespace std;

class bank_acc
{
        char cust_name[25],acc_type[20];
        float balance;
        int acc_no;

public:
        bank_acc(){
                balance = 500;
        }

        void get_data(){
                cout<<"Enter name: "<<endl;
                cin>>cust_name;
                cout<<"Enter account type [savings(s), fixed(f), current(c)]: "<<endl;
                cin>>acc_type;
                cout<<"Enter account number: "<<endl;
                cin>>acc_no;
        }

        void deposit()
        {
                int amount;
                cout<<"Enter amount to deposit: "<<endl;
                cin>>amount;
                if(amount<=0)
                {
                        cout<<"Amount should be greater than 0"<<endl;
                }
                else
                {
                        balance +=amount;
                        cout<<"Amount deposited"<<endl;
                        cout<<"Balance: "<<balance<<endl;
                }
        }
friend void withdraw(bank_acc &b);

void display(){                       
	cout<<"Customer Name: "<<cust_name<<endl;
        cout<<"Account Number: "<<acc_no<<endl;
        cout<<"Account Type: "<<acc_type<<endl;
        cout<<"Balance: "<<balance<<endl;             
}
};

void withdraw(bank_acc &b){
        int amount;
        cout<<"Enter the amout to be withdrawn: "<<endl;
        cin>>amount;
        if(amount>b.balance)
        {
                cout<<"Balance = "<<b.balance<<endl;
                cout<<"Insufficient balance"<<endl;
        }
        else
        {
                b.balance-=amount;
                cout<<"Amount withdrawn"<<endl;
        }
}


int main()
{
        bank_acc obj1,obj2;
        cout<<"For object 1: "<<endl;
        obj1.get_data();
        obj1.deposit();
        withdraw(obj1);
        obj1.display();
        cout<<"For object 2:"<<endl;
        obj2.get_data();
        obj2.deposit();
        withdraw(obj2);
        obj2.display();
	return 0;
}