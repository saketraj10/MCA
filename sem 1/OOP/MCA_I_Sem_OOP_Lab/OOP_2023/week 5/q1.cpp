//Program to create a class Matrix using 2-D array of integer and overloading operator == and + and -.
//Name: Saket Raj
//Reg No: 230970079
//Date: 15-09-2023
#include<iostream>
using namespace std;

class matrix
{
        int a[10][10],m,n,i,j;

        public:
        matrix()
        {
                m=n=10;
        }
        matrix(int p, int q)
        {
                m=p;
                n=q;
        }

        void get_element()
        {
                cout<<"enter the size of matrix:"<<endl;
                cout<<"rows: ";
                cin>>m;
                cout<<"columns: ";
                cin>>n;
                cout<<"enter elements for the array: "<<endl;
                for(i=0;i<m;i++)
                {
                        for(j=0;j<n;j++)
                        {
                                cin>>a[i][j];
                        }
                }
        }

        void display()
        {
                cout<<"elements of matrix:"<<endl;
                for(i=0;i<m;i++)
                {
                        for(j=0;j<n;j++)
                        {
                                cout<<"\t"<<a[i][j];
                        }
                        cout<<endl;
                }
        }
  bool operator== (matrix &obj)
        {
                if(m == obj.m && n== obj.n)
                {
                        return true;
                }
                else
                {
                        return false;
                }
        }
        matrix operator+ (matrix &obj)
        {
                matrix temp(m,n);
                for(int i=0;i<m;i++)
                {
                        for(int j=0;j<n;j++)
                        {
                                temp.a[i][j]=a[i][j] + obj.a[i][j];
                        }
                }
                return temp;
        }
        matrix operator- (matrix &obj)
        {
                matrix temp(m,n);
                for(int i=0;i<m;i++)
                {
                        for(int j=0;j<n;j++)
                        {
                                temp.a[i][j]=a[i][j] - obj.a[i][j];
                        }
                }
                return temp;
        }
};
int main()
{
        matrix m1,m2,m3,m4;
        cout<<"matrix for obj m1:"<<endl;
        m1.get_element();
        cout<<"matrix for obj m2:"<<endl;
        m2.get_element();
        cout<<"matrix 1"<<endl;
        m1.display();
        cout<<"matrix 2"<<endl;
        m2.display();
        if( m1 == m2)
        {
                m3 = m1 + m2;
                m4 = m1 - m2;
        }
        else
        {
                cout<<"matrix dimensions does not match"<<endl;
        }
        cout<<"Sum of two matrix : "<<endl;
        m3.display();
        cout<<"Difference of two matrix: "<<endl;
        m4.display();
        return 0;
}