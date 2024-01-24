//Program for swapping two integers, floats, and characters using function-overloading concept
//Name: Saket Raj
//Reg No: 230970079
//Date: 31-08-2023

#include<iostream>
using namespace std;
void swap(int &a,int &b);
void swap(float &a, float &b);
void swap(char &a,char &b);
int main()
{
        int ix,iy;
        float fx,fy;
        char cx,cy;
        cout<<"enter two integers: "<<endl;
        cin>>ix>>iy;

        cout<<"Integers: \n Before swapping:"<<endl;
        cout<<"\n\tnumber1: "<<ix<<"\n\tnumber2: "<<iy<<endl;
        swap(ix,iy);
        cout<<"After swapping"<<endl;
        cout<<"\n\tnumber1: "<<ix<<"\n\tnumber2: "<<iy<<endl;

        cout<<"\nenter two floating point numbers: "<<endl;
        cin>>fx>>fy;

	cout<<"Float: \n Before swapping:"<<endl;
        cout<<"\n\tnumber1: "<<fx<<"\n\tnumber2: "<<fy<<endl;
        swap(fx,fy);
        cout<<"After swapping"<<endl;
        cout<<"\n\tnumber1: "<<fx<<"\n\tnumber2: "<<fy<<endl;

        cout<<"\nenter two characters: "<<endl;
        cin>>cx>>cy;

        cout<<"Characters: \n Before swapping:"<<endl;
        cout<<"\n\tcharacter 1: "<<cx<<"\n\tcharacter 2: "<<cy<<endl;
        swap(cx,cy);
        cout<<"After swapping"<<endl;
        cout<<"\n\tcharacter 1: "<<cx<<"\n\tcharacter 2: "<<cy<<endl;

        return 0;
}

void swap( int &a ,int &b)
{
        int temp;
        temp=a;
        a=b;
        b=temp;
}

void swap(float &a,float &b)
{
        float temp;
        temp=a;
        a=b;
        b=temp;
}

void swap(char &a,char &b)
{
        char temp;
        temp=a;
        a=b;
        b=temp;
}