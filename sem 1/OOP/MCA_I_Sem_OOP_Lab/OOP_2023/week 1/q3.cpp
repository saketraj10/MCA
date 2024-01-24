//Program to calculate the area of a circle and a triangle
//Name: Saket Raj
//Reg No: 230970079
//Date: 11-08-2023
#include<iostream>
using namespace std;
int main(){
        float radius, area_of_circle, base, height, area_of_triangle;

        cout<<"Enter the radius of circle: "<<endl;
        cin>>radius;

        cout<<"Enter the base and height of triangle: "<<endl;
        cin>>base>>height;

        area_of_circle = 3.14*radius*radius;

        area_of_triangle = .5*base*height;

        cout<<"Area of circle: "<<area_of_circle<<endl;

        cout<<"Area of triangle: "<<area_of_triangle<<endl;

        return 0;
}