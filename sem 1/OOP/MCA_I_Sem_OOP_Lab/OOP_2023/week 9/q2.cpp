#include<iostream>
using namespace std;
class shape{
    protected:
    double val1;
    double val2;
    public:
    void get_data(){
        cout<<"Enter the value1: ";
        cin>>val1;
        cout<<"Enter the value2 :";
        cin>>val2;
    }
    virtual void display_area() = 0;
};
class triangle: public shape{
    double area;
    public:
    void display_area(){
        area = 0.5 * val1 * val2;
        cout<<"Base= "<<val1<<endl;
        cout<<"Height= "<<val2<<endl;
        cout<<"Area of triangle= "<<area<<endl;
    }
};
class rectangle: public shape{
    double area;
    public:
    void display_area(){
        area = val1 * val2;
        cout<<"Length= "<<val1<<endl;
        cout<<"Breadth= "<<val2<<endl;
        cout<<"Area of rectangle= "<<area<<endl;
    }
};
int main(){
    triangle t;
    rectangle r;
    cout<<"Triangle: "<<endl;
    t.get_data();
    t.display_area();
    cout<<"Rectangle: "<<endl;
    r.get_data();
    r.display_area();
    return 0;
}