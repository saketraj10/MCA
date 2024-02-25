//Represent a polynomial using 1-D array and perform addition operation on two polynomials
//Saket Raj
//230970079
//15-01-2023
#include<iostream>
using namespace std;
struct poly{
        int coef;
        int exp;
};
int main(){
        int coef1,coef2;
        cout<<"enter the no of coefficient of polynomial 1 : "<<endl;
        cin>>coef1;

        int size1 = coef1 + 1;

        poly p1[size1];

        p1[0].coef = coef1;

        cout<<"enter the polynomial 1 : "<<endl;
        for(int i=1; i<size1; i++){
                cout<<"enter the value of coefficient: ";
                cin>>p1[i].coef;
                cout<<"enter the value of exponent: ";
                cin>>p1[i].exp;
        }
        cout<<"display polynomial 1 : "<<endl;
        for(int i=1; i<size1; i++){
                if(p1[i].exp==0)
                        cout<<" + "<<p1[i].coef<<" ";
                else
                cout<<" + "<<p1[i].coef<<"x^"<<p1[i].exp<<" ";
        }
	 cout<<endl;

        cout<<"enter the no of coefficient of polynomial 2 : "<<endl;
        cin>>coef2;
        int size2 = coef2 + 1;
        poly p2[size2];
        p2[0].coef = coef2;
        cout<<"enter the polynomial 2 : "<<endl;
        for(int i=1; i<size2; i++){
                cout<<"enter the value of coefficient: ";
                cin>>p2[i].coef;
                cout<<"enter the value of exponent: ";
                cin>>p2[i].exp;
        }
        cout<<"display polynomial 2 : "<<endl;
        for(int i=1; i<size2; i++){
                if(p2[i].exp==0)
                        cout<<" + "<<p2[i].coef<<" ";
                else
                cout<<" + "<<p2[i].coef<<"x^"<<p2[i].exp<<" ";
        }
        cout<<endl;

        int size3 = size1 + size2;
        poly p3[size3];

        int x = 1;
        int y = 1;
        int z = 1;
	 while(x < size1 || y < size2){
                if(p1[x].exp == p2[y].exp){
                        p3[z].coef = p1[x].coef + p2[y].coef;
                        p3[z].exp = p1[x].exp;
                        x++;
                        y++;
                        z++;
                }
                else if(p1[x].exp < p2[y].exp){
                        p3[z].coef = p2[y].coef;
                        p3[z].exp = p2[y].exp;
                        y++;
                        z++;
                }
                else{
                        p3[z].coef = p1[x].coef;
                        p3[z].exp = p1[x].exp;
                        x++;
                        z++;
                }
        }
        cout<<"display the sum of polynomial 1 and polynomial 2 : "<<endl;
        for(int i=1; i<z; i++){
                if(p3[i].coef==0) continue;
                if(p3[i].exp==0)
                        cout<<" + "<<p3[i].coef<<" ";
                else
                cout<<" + "<<p3[i].coef<<"x^"<<p3[i].exp<<" ";
        }
        cout<<endl;

        return 0;
}