#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the no of process: ";
    cin>>n;

    int p[n], at[n], bt[n], ft[n], wt[n], tat[n];
    float avgwt, avgtat;
    int temp;

    cout<<"Enter the process id, arrival time and burst time: "<<endl;
    for(int i=0; i<n; i++){
        cout<<"Enter the process id: ";
        cin>>p[i];
        cout<<"Enter the arrival time: ";
        cin>>at[i];
        cout<<"Enter the burst time: ";
        cin>>bt[i];
    }

    //sort it on the basis of arrival time
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(at[j]>at[j+1]){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;

                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;

                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
            }
            //if arrival time than, sort it ont he basis of burst time
            else if(at[j]==at[j+1])
            {
                if(bt[j]>bt[j+1]){
                    temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;

                    temp = at[j];
                    at[j] = at[j+1];
                    at[j+1] = temp;

                    temp = bt[j];
                    bt[j] = bt[j+1];
                    bt[j+1] = temp;
                }
            }
        }
    }

    //calculate finish time
    for(int i=0; i<n; i++){
        if(i==0){
            ft[i] = bt[i] + at[i];
        }
        else{
            temp = 0;
            if(ft[i-1]<at[i]){
                temp = at[i] - ft[i-1];
            }
            ft[i] = bt[i] + ft[i-1] + temp;
        }
    }

    //calculate turnaround time
    for(int i=0; i<n; i++){
        tat[i] = ft[i] - at[i];
    }

    //calculate waiting time
    for(int i=0; i<n; i++){
        wt[i] = tat[i] - bt[i];
    }

    //for avg at and avg tat
        float totalwt = 0;
        float totaltat = 0;
        cout<<"Process id\t arrival time\t burst time\t waiting time\t turnaround time\t finish time"<<endl;
        for(int i=0; i<n; i++)
        {
                cout<<p[i]<<"\t\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\t\t\t"<<ft[i]<<endl;
                totalwt += wt[i];
                totaltat += tat[i];
        }
        avgwt = totalwt/n;
        avgtat = totaltat/n;
        cout<<"avg waiting time: "<<avgwt<<endl;
        cout<<"avg turnaround time: "<<avgtat<<endl;
        return 0;
}