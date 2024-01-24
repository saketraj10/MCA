#include<iostream>
using namespace std;
class Employee
{
    int emp_code;
    char emp_name[25];
    public:
    void eset()
    {
        cout<<"Enter emp code: "<<endl;
        cin>>emp_code;
        cout<<"Enter emp name: "<<endl;
        cin>>emp_name;
    }
    void edisplay()
    {
        cout<<"Emp code: "<<emp_code<<endl;
        cout<<"Emp name: "<<emp_name<<endl;
    }
};
class Faculty: public Employee
{
    char qualification[25];
    float yearofexp;
    public:
    void fset()
    {
        eset();
        cout<<"Enter qualification: "<<endl;
        cin>>qualification;
        cout<<"Enter year of experience: "<<endl;
        cin>>yearofexp;
    }
    void fdisplay()
    {
        edisplay();
        cout<<"Qualification: "<<qualification<<endl;
        cout<<"Year of experience: "<<yearofexp<<endl;
    }
};
class Nonteaching: public Employee
{
    char grade[25];
    public:
    void nset()
    {
        eset();
        cout<<"Enter grade: "<<endl;
        cin>>grade;
    }
    void ndisplay()
    {
        edisplay();
        cout<<"Grade: "<<grade<<endl;
    }
};
class Permanent: public Faculty
{
    float basic_pay;
    float aced_allowance;
    public:
    void pset()
    {
        fset();
        cout<<"Enter basic pay: "<<endl;
        cin>>basic_pay;
        cout<<"Enter acedmic allowance: "<<endl;
        cin>>aced_allowance;
    }
    void pdisplay(){
        fdisplay();
        cout<<"Basic Pay: "<<basic_pay<<endl;
        cout<<"Acedmic allowance: "<<aced_allowance<<endl;
    }
};
class Contract: public Faculty
{
    float pro_yrs;
    public: 
    void cset()
    {
        fset();
        cout<<"Enter probation years: "<<endl;
        cin>>pro_yrs;
    }
    void cdisplay(){
        fdisplay();
        cout<<"Probation years: "<<pro_yrs<<endl;
    }
};
int main()
{
    Permanent p1;
    Contract c1;
    Nonteaching nont1;
    cout<<"Enter data of permanent: "<<endl;
    p1.pset();
    cout<<endl;
    cout<<"Enter data of Contact: "<<endl;
    c1.cset();
    cout<<endl;
    cout<<"Enter data of nonteaching: "<<endl;
    nont1.nset();
    cout<<endl;
    cout<<"Display Permanent: "<<endl;
    p1.pdisplay();
    cout<<endl;
    cout<<"Display Contract: "<<endl;
    c1.cdisplay();
    cout<<endl;
    cout<<"Display nonteaching: "<<endl;
    nont1.ndisplay();

    return 0;
}