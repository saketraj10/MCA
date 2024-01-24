//Program to generates all the possible combination of the given 3 digit number
//Name: Saket Raj
//Reg No: 230970079
//Date: 16-08-2023
#include<iostream>
using namespace std;
int main(){
        int a[3];
        cout<<"Enter three digit number: "<<endl;
        cin>>a[0]>>a[1]>>a[2];

        for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                        for(int k=0; k<3; k++){
                                if(i!=j && i!=k && j!=k){
                                        cout<<endl<<a[i]<<a[j]<<a[k];
                                }
                        }
                }
        }
        return 0;
}