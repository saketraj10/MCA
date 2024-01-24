#include<iostream>
using namespace std;
inline int cube(int r){
    return r*r*r;
}
int main(){
    int r;
    cout<<"Enter any integer for cube: "<<endl;
    cin>>r;
    cout<<"Cube is "<<cube(r);
    return 0;
}