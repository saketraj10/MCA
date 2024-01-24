#include<iostream>
using namespace std;
class Complex
{
        int real,img;
        public :
        void read()
        {
                cout<<"Enter the real part of complex number:";
                cin>>real;
                cout<<"Enter the imaginary part of complex number:";
                cin>>img;
        }
        void display()
        {
                cout<<"\nthe real part of complex number:"<<real<<endl;
                cout<<"\nthe imaginary part of complex number:"<<img<<endl;
        }
        Complex add(int x,Complex &r2)
        {
                Complex temp;
                temp.real=x+r2.real;
                temp.img=x+r2.img;
                return temp;

        }
	Complex add(Complex &c1,Complex &c2)
        {
                Complex temp;
                temp.real=c1.real+c2.real;
                temp.img=c1.img+c2.img;
                return temp;
        }
};
int main()
{
        Complex c1,c2,c3,c4;
        int num;
        c1.read();
        c2.read();
        cout<<"Enter the number:";
        cin>>num;
        c3=c3.add(num,c1);
        c4=c4.add(c1,c2);
        cout<<"result after adding with number\n";
        c3.display();
        cout<<"result after adding with complex number\n";
        c4.display();
        return 0;
}