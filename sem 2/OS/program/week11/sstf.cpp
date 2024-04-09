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

        for(int i=0; i<n; i++){
            for(int j=0; j<n-1; j++){
                if(rwHead[j]>rwHead[j+1]){
                    int temp = rwHead[j];
                    rwHead[j] = rwHead[j+1];
                    rwHead[j+1] = temp;
                }
            }
        }

        int minidx = -1;
        for(int i=0; i<n; i++){
            if(currentposition<rwHead[i]) break;
            else minidx = i;
        }

        int minv = rwHead[minidx];
        int maxv = rwHead[minidx+1];

        int mindif = currentposition-minv;
        int maxdiv = maxv-currentposition;

        bool flag;
        if(mindif<maxdiv){
            flag = true;
        }
        else flag = false;

        int p = 1;
        if(flag){
            for(int i=minidx; i>=0; i--){
                sequence[p++] = rwHead[i];
                totalNoOfTrack += abs(currentposition - rwHead[i]);
                currentposition = rwHead[i];
            }
            for(int i=minidx+1; i<n; i++){
                sequence[p++] = rwHead[i];
                totalNoOfTrack += abs(currentposition - rwHead[i]);
                currentposition = rwHead[i];
            }
        }
        else{
            for(int i=minidx+1; i<n; i++){
                sequence[p++] = rwHead[i];
                totalNoOfTrack += abs(currentposition - rwHead[i]);
                currentposition = rwHead[i];
            }
            for(int i=minidx; i>=0; i--){
                sequence[p++] = rwHead[i];
                totalNoOfTrack += abs(currentposition - rwHead[i]);
                currentposition = rwHead[i];
            }
        }
        
        cout<<"Total no of Track: "<<totalNoOfTrack<<endl;
        cout<<"Seek Sequence: "<<endl;
        for(int i=0; i<n+1; i++){
                cout<<sequence[i]<<" ";
        }
        cout<<endl;

        return 0;

}