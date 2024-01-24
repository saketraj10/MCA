#include<iostream>
using namespace std;
class student{
    int regno;
    char name[30];
    public:
    void putdata(){
        cout<<"Enter student details: "<<endl;
        cout<<"Enter Regno: ";
        cin>>regno;
        cout<<"Enter Name: ";
        cin>>name;
    }
    void display(){
        cout<<"Student Details: "<<endl;
        cout<<"Regno: "<<regno<<endl;
        cout<<"Name: "<<name<<endl;
    }
};
class exam: virtual public student{
    public:
    int m1,m2;
    void putdata_exam(){
        putdata();
        cout<<"Enter 2 subject marks: "<<endl;
        cout<<"Subject 1: ";
        cin>>m1;
        cout<<"Subject 2: ";
        cin>>m2;
    }
    void display_exam(){
        display();
        cout<<"Marks of subject: "<<endl;
        cout<<"Subject 1: "<<m1<<endl;
        cout<<"Subject 2: "<<m2<<endl;
    }
};
class sports: virtual public student{
    public:
    char sport[30];
    float weightage;
    void putdata_sports(){
        cout<<"Enter sports details: "<<endl;
        cout<<"Sports name: ";
        cin>>sport;
        cout<<"Weightage: ";
        cin>>weightage;
    }
    void display_sports(){
        cout<<"Details of sports: "<<endl;
        cout<<"Sports name: "<<sport<<endl;
        cout<<"weightage: "<<weightage<<endl;
    }
};
class result: public exam, public sports{
    float total, result;
    public:
    void putdata_result(){
        putdata_exam();
        putdata_sports();
    }
    void display_result(){
        display_exam();
        display_sports();

        total = m1 + m2;
        result = total * weightage / 100;
        cout<<"Total marks: "<<total<<endl;
        cout<<"Result: "<<result<<endl;
    }
};
int main(){
    result r1;
    r1.putdata_result();
    r1.display_result();
    return 0;
}