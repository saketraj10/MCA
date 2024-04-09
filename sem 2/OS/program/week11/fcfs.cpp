#include<iostream>
using namespace std;
int main(){
        int n;
        cout<<"Enter the size of r/w head: ";
        cin>>n;

        int rwHead[n];
        cout<<"Enter the value of rwHead: "<<endl;
        for(int i=0; i<n; i++)
        {
                cin>>rwHead[i];
        }

        int currentposition;
        cout<<"Enter the current position: ";
        cin>>currentposition;

        int totalNoOfTrack = 0;
        int sequence[n+1];
        sequence[0] = currentposition;

        int p = 1;
        for(int i=0; i<n; i++)
        {
                sequence[p++] = rwHead[i];
                totalNoOfTrack += abs(currentposition - rwHead[i]);
                currentposition = rwHead[i];
        }
        cout<<"Total no of Track: "<<totalNoOfTrack<<endl;
        cout<<"Seek Sequence: "<<endl;
        for(int i=0; i<n+1; i++){
                cout<<sequence[i]<<" ";
        }
        cout<<endl;

        return 0;

}