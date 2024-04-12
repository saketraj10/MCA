//lower the no higher the priority
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout<<"Enter the no of process: ";
    cin>>n;
    // p = process id, at = arrival time, bt = burst time, pr = priority, ct = completion time, wt = waiting time, tat = turnaround time, br = burst remaining
    int p[n], at[n], bt[n], pr[n], ct[n], wt[n], tat[n], br[n];
    float avgtat=0, avgwt = 0, totalwt = 0, totaltat = 0;
    cout<<"Enter the process id, arrival time and burst time and priority: "<<endl;
    for(int i=0; i<n; i++){
        cout<<"Enter process id: ";
        cin>>p[i];
        cout<<"Enter arrival time: ";
        cin>>at[i];
        cout<<"Enter burst time: ";
        cin>>bt[i];
        cout<<"Enter priority: ";
        cin>>pr[i];
        br[i] = bt[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(at[j]>at[j+1])
            {
                swap(p[j],p[j+1]);
                swap(at[j],at[j+1]);
                swap(bt[j],bt[j+1]);
                swap(br[j],br[j+1]);
                swap(pr[j],pr[j+1]);
            }
        }
    }

    int currentTime = 0;
    while(true)
    {
        int currentHighestPriorityIndex = -1;
        int currentHighestPriority = INT_MAX;
        bool isAllCompleted = true;

        for(int i=0; i<n; i++)
        {
            if(br[i] > 0)
            {
                isAllCompleted = false;
                if(at[i] <= currentTime)
                {
                    if(pr[i] < currentHighestPriority)
                    {
                        currentHighestPriority = pr[i];
                        currentHighestPriorityIndex = i;
                    }
                }
            }
        }

        if(isAllCompleted) break;
        br[currentHighestPriorityIndex]--;
        currentTime++;
        if(br[currentHighestPriorityIndex]==0)
        {
            ct[currentHighestPriorityIndex] = currentTime;
        }
    }

    cout<<"process id\t completion time\t waiting time\t turnaround time"<<endl;
    for(int i=0; i<n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i]- bt[i];
        cout<<p[i]<<"\t\t\t"<<ct[i]<<"\t\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }

    for(int i=0; i<n; i++)
    {
        totaltat += tat[i];
        totalwt += wt[i];   
    }
    avgwt = totalwt/n;
    avgtat = totaltat/n;
    cout<<"avg waiting time: "<<avgwt<<endl;
    cout<<"avg turnaround time: "<<avgtat<<endl;
    return 0;
}