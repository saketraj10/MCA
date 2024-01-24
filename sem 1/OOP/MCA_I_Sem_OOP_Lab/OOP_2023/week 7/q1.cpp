#include<iostream>
using namespace std;
class person
{
    int id;
    char name[25];
    public:
    void pset()
    {
        cout<<"Enter id:"<<endl;
        cin>>id;
        cout<<"Enter name:"<<endl;
        cin>>name;
    }
    void pget()
    {
        cout<<"id: "<<id<<endl;
        cout<<"name: "<<name<<endl;
    }
};
class Teaching: public person
{
    char subject[25];
    public:
    void tset()
    {
        pset();
        cout<<"Enter subject: "<<endl;
        cin>>subject;
    }
    void tget(){
        pget();
        cout<<"Subject: "<<subject<<endl;
    }
};
class Instructor: public person
{
    public:
    void iset()
    {
        pset();
    }
    void iget()
    {
        pget();
    }
};
class Nonteaching: public person
{
    char dept[20];
    public:
    void nset()
    {
        pset();
        cout<<"Enter the dept: "<<endl;
        cin>>dept;
    }
    void nget()
    {
        pget();
        cout<<"dept: "<<dept<<endl;
    }
};
int main()
{
    int n1, n2, n3;
    cout<<"Enter the no of teaching staff: "<<endl;
    cin>>n1;
    Teaching teach[n1];
    for(int i=0; i<n1; i++)
    {
        teach[i].tset();
        cout<<endl;
    }
    cout<<"Enter the no of instructor: "<<endl;
    cin>>n2;
    Instructor inst[n2];
    for(int i=0; i<n2; i++)
    {
        inst[i].iset();
        cout<<endl;
    }
    cout<<"Enter the no of nonteaching staff: "<<endl;
    cin>>n3;
    Nonteaching nont[n3];
    for(int i=0; i<n3; i++)
    {
        nont[i].nset();
        cout<<endl;
    }

    cout<<"Display teaching staff: "<<endl;
    for(int i=0; i<n1; i++)
    {
        teach[i].tget();
        cout<<endl;
    }
    cout<<endl;
    cout<<"Display Instructor: "<<endl;
    for(int i=0; i<n2; i++)
    {
        inst[i].iget();
        cout<<endl;
    }
    cout<<endl;
    cout<<"Display nonteaching: "<<endl;
    for(int i=0; i<n3; i++)
    {
        nont[i].nget();
        cout<<endl;
    }
    return 0;
}