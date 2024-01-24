//Program to create employee structure and perform operations
//Name: Saket Raj
//Reg No: 230970079
//Date: 31-08-2023
#include<iostream>
#define MAX_SIZE 100
using namespace std;

struct Employee
{
        int emp_no;
        char name[MAX_SIZE];
        float basic,DA,IT;
        double net_sal;
};

Employee add_Employee()
{
        Employee emp;
        cout<<"Enter employee details"<<endl;
        cout<<"number: ";
        cin>>emp.emp_no;
        cout<<"name: ";
        cin>>emp.name;
        cout<<"basic salary: ";
        cin>>emp.basic;

        return emp;
}

void calc_Salary(Employee &emp)
{
        emp.DA = emp.basic * 0.12;
        emp.IT = (emp.basic + emp.DA) * 0.18;
        emp.net_sal = (emp.basic + emp.DA) - emp.IT;
}

void display(Employee emp)
{
        cout<<"------------------------------------------------"<<endl;
        cout<<"Name : "<<emp.name<<endl;
        cout<<"Employee Number: "<<emp.emp_no<<endl;
        cout<<"Basic: "<<emp.basic<<endl;
        cout<<"DA : "<<emp.DA<<endl;
        cout<<"IT: "<<emp.IT<<endl;
        cout<<"Net Salary: "<<emp.net_sal<<endl;
}

int main()
{
        int no_of_employees;
        Employee employees[MAX_SIZE];
        system("clear");
        cout<<"Enter the number of employees (MAX="<<MAX_SIZE<<")"<<endl;
        cin>>no_of_employees;
        for(int i=0;i<no_of_employees;i++)
        {
                employees[i] = add_Employee();
                calc_Salary(employees[i]);
        }
        cout<<"employee list: "<<endl;
        for(int i=0;i<no_of_employees;i++)
        {
                display(employees[i]);
        }
        return 0;
}