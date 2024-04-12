#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;

    int p[n], at[n], bt[n], rt[n], ft[n], wt[n], tat[n];
    float avgwt, avgtat;
    int currentTime = 0, completed = 0;

    cout<<"Enter process id, arrival time , and burst time: "<<endl;
    for(int i=0; i<n; i++){
        cout<<"Process id: ";
        cin>>p[i];
        cout<<"Arrival time: ";
        cin>>at[i];
        cout<<"Burst time: ";
        cin>>bt[i];
        rt[i] = bt[i];
    }

    cout<<"process id\t turnaround time\t waiting time"<<endl;

    while(completed!=n){
        int smallest = -1;
        for(int i=0; i<n; i++){
            if(at[i]<=currentTime && rt[i]>0){
                if(smallest==-1 || rt[i]<rt[smallest]){
                    smallest = i;
                }
            }
        }
        if(smallest==-1){
            currentTime++;
            continue;
        }
        
        rt[smallest]--;

        if(rt[smallest]==0){
            completed++;
            ft[smallest] = currentTime + 1;
            wt[smallest] = ft[smallest] - at[smallest] - bt[smallest];
            tat[smallest] = ft[smallest] - at[smallest];
            cout<<p[smallest]<<"\t\t"<<tat[smallest]<<"\t\t\t"<<wt[smallest]<<endl;
        }
        currentTime++;
    }

    float totalwt = 0, totaltat = 0;
    for(int i=0; i<n; i++){
        totalwt += wt[i];
        totaltat += tat[i];
    }

    avgwt = totalwt/n;
    avgtat = totaltat/n;

    cout<<"avg waiting time: "<<avgwt<<endl;
    cout<<"avg turnaround time: "<<avgtat<<endl;

    return 0;
}