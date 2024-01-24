//Program to generate prime numbers between two limits
//Name: Saket Raj
//Reg No: 230970079
//Date: 25-08-2023
#include<iostream>
using namespace std;
int main(){
        int low, high, res;
        bool flag = true;
        cout<<"Enter the lower range for prime number: "<<endl;
        cin>>low;

        cout<<"Enter the highest range for prime number: "<<endl;
        cin>>high;

        cout<<"All prime number between "<<low<<" to "<<high<<": "<<endl;

        while(low<=high){
                flag = true;
                for(int i=2; i<=low/2; i++){
                        if(low % i == 0){
                                flag = false;
                                break;
                        }
                }
                if(flag == 1)
                {
                        cout<<low<<" "<<endl;
                }
		low++;
        }
        return 0;
}