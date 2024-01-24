//Program to accept stduent details such as Name, Registration number, Year of joining, Semester number, marks in five s
//ubjects. Calculate the average marks as total marks divide by five. Design a score card as based on the following gradin
//g criteria
//Name: Saket Raj
//Reg No: 230970079
//Date: 16-08-2023
#include<iostream>
using namespace std;
int main(){
        char name[20];
        char grade;
        int registration, year, sem ;
        float mark1, mark2, mark3, mark4, mark5, total, avg;

        cout<<"Enter the name: "<<endl;
        cin>>name;

        cout<<"Enter the registration number: "<<endl;
        cin>>registration;

        cout<<"Enter the year of joining: "<<endl;
        cin>>year;

        cout<<"Enter the semester number: "<<endl;
        cin>>sem;

        cout<<"Enter the marks of five subject: "<<endl;
        cin>>mark1>>mark2>>mark3>>mark4>>mark5;

        total = (mark1+mark2+mark3+mark4+mark5);
	 avg = total/5;


        if(avg>=90){
                grade='A';
        }
        else if(avg>=80 && avg<=89){
                grade='B';
        }
        else if(avg>=61 && avg<=79){
                grade='C';
        }
        else if(avg>=51 && avg<=59){
                grade='D';
        }
        else if(avg>=41 && avg<=49){
                grade='E';
        }
        else{
                grade='F';
        }

  if(mark1<=40 || mark2<=40 || mark3<=40 || mark4<=40 || mark5<=40){
                grade='F';
        }

	 cout<<"-------------------------------------------------------------------------------------------"<<endl;

        cout<<"                              Score Card for Student: "<<name<<endl;
        cout<<"Registration Number: "<<registration<<"                                 Semester: "<<sem<<endl;
        cout<<"Year: "<<year<<endl;
        cout<<"Grade Assigned:"<<endl;
        cout<<endl;
        cout<<"Serial No.               Subject Name            Marks Scored(out of 100)"<<endl;
        cout<<"_________________________________________________________________________"<<endl;
        cout<<"1                Object Oriented Programming             "<<mark1<<endl;
        cout<<"2                DBMS                                    "<<mark2<<endl;
        cout<<"3                Research Methodology                    "<<mark3<<endl;
        cout<<"4                Computational Mathematics               "<<mark4<<endl;
        cout<<"5                Web Technologies                        "<<mark5<<endl;
        cout<<"                                         Total:          "<<total<<endl;
        cout<<"                                       Average:          "<<avg<<endl;
        cout<<"                                         Grade:          "<<grade<<endl;

        return 0;
}