#include<iostream>
using namespace std;
int main(){
    int n,rem;
    cout<<"Enter any integer value for binary conversion: "<<endl;
    cin>>n;
    int a[10];
    int i=0;
    while(n>0){
        a[i] = n%2;
        n /= 2;
        i++;
    }
    for(int j=i-1; j>=0; j--){
        cout<<a[j];
    }
    cout<<endl;

    cout<<"Enter any binary number for decimal conversion: "<<endl;
    cin>>n;
    int decimal = 0;
    int weight = 1;
    while(n>0){
        rem = n%10;
        n /= 10;
        decimal = decimal + rem * weight;
        weight *= 2;
    }
    cout<<"Decimal value: "<<decimal<<endl;
    return 0;
}