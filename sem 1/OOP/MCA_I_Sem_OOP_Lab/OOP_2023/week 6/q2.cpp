//Program to perform additon and subtraction on two complex numbers using operator overloading using member functions
//Name: Saket Raj
//Reg No: 230970079
//Date: 15-09-2023
#include<iostream>
using namespace std;
class complex{
        public:
        int real,img;
        complex(){
                real = 0;
                img = 0;
        }
        complex(int r, int i){
                real = r;
                img = i;
        }
        complex operator+( complex &p){
                complex temp;
                temp.real = real + p.real;
                temp.img = img + p.img;
                return temp;
        }

        complex operator-(complex &p){
                complex temp;
                temp.real = real - p.real;
                temp.img = img - p.img;
                return temp;
        }
        void display(){
                cout<<"Real: "<<real<<endl;
                cout<<"Img: "<<img<<endl;
        }
};
int main(){
        complex c1(4,5),c2(5,9);
        complex c3, c4;
        c3 = c1+c2;
        c4 = c1-c2;
        cout<<"After addition: "<<endl;
        c3.display();
        cout<<"After subtraction: "<<endl;
        c4.display();
        return 0;
}