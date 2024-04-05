#include<iostream>
using namespace std;
int main(){
        int n;
        cout<<"Enter the size of r/w head: ";
        cin>>n;

        int m;
        cout<<"Enter the size of disk: ";
        cin>>m;
        int rwHead[n];
        cout<<"Enter the value of rwHead between(0-"<<m-1<<") : "<<endl;
        for(int i=0; i<n; i++)
        {
                cin>>rwHead[i];
        }

        int currentposition;
        cout<<"Enter the current position: between(0-"<<m-1<<") : ";
        cin>>currentposition;

        int totalNoOfTrack = 0;

        for(int i=0; i<n; i++)
        {
                totalNoOfTrack += abs(currentposition - rwHead[i]);
                currentposition = rwHead[i];
        }
        cout<<"Total no of Track: "<<totalNoOfTrack<<endl;

        return 0;

}