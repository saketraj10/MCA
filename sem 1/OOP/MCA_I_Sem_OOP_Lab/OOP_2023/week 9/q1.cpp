//Program to model the above relationship. Assume proper data members and member functions for each class
//Name: Saket Raj
//Reg No: 230970079
//Date: 02-11-2023
#include<iostream>
using namespace std;
class employee{
        int id;
        char name[30];
        public:
        void eput(){
                cout<<"Enter id: ";
                cin>>id;
                cout<<"Enter name: ";
                cin>>name;
        }
        void edisplay(){
                cout<<"id: "<<id<<endl;
                cout<<"name: "<<name<<endl;
        }
        virtual void cal() = 0;
};
class education{
        char dept[30];
        char course[30];
        public:
        void edput(){
                cout<<"Enter dept: ";
                cin>>dept;
                cout<<"Enter course: ";
                cin>>course;
        }
        void eddisplay(){
                cout<<"dept: "<<dept<<endl;
                cout<<"course: "<<course<<endl;
        }
};
class laborer: public employee{
        float sal,tax;
        char subject[30];
        public:
        void lput(){
                eput();
                cout<<"Enter subject: ";
                cin>>subject;
                cout<<"Enter sal:";
                cin>>sal;
        }
        void cal(){
                if(sal>50000){
                        tax = sal * .2;
                }
                else{
                        tax = sal * .1;
                }
        }
        void ldisplay(){
                edisplay();
                cout<<"subject: "<<subject<<endl;
                cout<<"Salary: "<<sal<<endl;
                cout<<"Tax: "<<tax<<endl;
                cout<<"Salary after tax: "<<(sal-tax)<<endl;
        }
};
class scientist: public employee, public education{
        char field[30];
        float sal, tax;
        public:
        void sput(){
                eput();
                edput();
                cout<<"Enter field: ";
                cin>>field;
                cout<<"Enter salary: ";
                cin>>sal;
        }
        void cal(){
                if(sal>50000){
                        tax = sal * .2;
                }
                else{
                        tax = sal * .1;
                }
        }
        void sdisplay(){
                edisplay();
                eddisplay();
                cout<<"field: "<<field<<endl;
                cout<<"Salary: "<<sal<<endl;
                cout<<"Tax: "<<tax<<endl;
                cout<<"Salary after tax: "<<(sal-tax)<<endl;
        }
};
class manager: public employee, public education{
        char post[30];
        float sal, tax;
        public:
        void mput(){
                eput();
                edput();
                cout<<"Enter post: ";
                cin>>post;
                cout<<"Enter salary: ";
                cin>>sal;
        }
        void cal(){
                if(sal>50000){
                        tax = sal * .2;
                }
                else{
                        tax = sal * .1;
                }
        }
        void mdisplay(){
                edisplay();
                eddisplay();
                cout<<"post: "<<post<<endl;
                cout<<"Salary: "<<sal<<endl;
                cout<<"Tax: "<<tax<<endl;
                cout<<"Salary after tax: "<<sal-tax<<endl;
        }
};
int main(){
        laborer l1;
        scientist s1;
        manager m1;
        cout<<"Enter the details of Laborer: "<<endl;
        l1.lput();
        l1.cal();
        cout<<"Enter the details of scientist: "<<endl;
        s1.sput();
        s1.cal();
        cout<<"Enter the details of manager: "<<endl;
        m1.mput();
        m1.cal();
        cout<<"Display the details of Laborer: "<<endl;
        l1.ldisplay();
        cout<<"Display the details of scientist: "<<endl;
        s1.sdisplay();
        cout<<"Display the details of manager: "<<endl;
        m1.mdisplay();

        return 0;
}