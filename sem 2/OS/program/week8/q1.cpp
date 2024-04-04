#include<iostream>
using namespace std;
int main()
{
        int n;
        cout<<"Enter the no of process: ";
        cin>>n;
        // p means process id, at means arrival time, bt means burst time, ft means finish time, wt means wait time, tat means turn around time
        int p[n], at[n], bt[n], rt[n], ft[n], wt[n], tat[n];
        float awt,atat;
        int completionTime, i, smallest;
        int remain = 0, time, sum_wait=0, sum_turnaround=0;

        cout<<"Enter the Process id, arrival time and burst time: "<<endl;
        for(int i=0; i<n; i++)
        {
                cout<<"Enter process id: ";
                cin>>p[i];
                cout<<"Enter arrival time: ";
                cin>>at[i];
                cout<<"Enter burst time: ";
                cin>>bt[i];
                rt[i] = bt[i];
        }

        cout<<"process id \t Turnaround Time \t Waiting Time"<<endl;
        for(time=0; remain!=n; time++)
        {
            smallest = -1;
            for(i=0; i<n; i++)
            {
                if(at[i]<=time && rt[i]>0)
                {
                    if(smallest == -1 || rt[i]<rt[smallest]){
                        smallest = i;
                    }
                }
            }
            if(smallest!=-1){
                rt[smallest]--;
                if(rt[smallest]==0)
                {
                    remain++;
                    completionTime = time+1;
                    wt[smallest] = completionTime - bt[smallest] - at[smallest];
                    tat[smallest] = completionTime - at[smallest];
                    sum_wait = sum_wait + completionTime - bt[smallest]-at[smallest];
                    sum_turnaround = sum_turnaround + completionTime - at[smallest];
                    cout<<p[smallest]<<"\t\t"<<tat[smallest]<<"\t\t\t"<<wt[smallest]<<endl;
                }
            }
        }
        cout<<endl;
        awt = sum_wait/n;
        atat = sum_turnaround/n;
        cout<<"avg waiting time: "<<awt<<endl;
        cout<<"avg turnaround time: "<<atat<<endl;

        return 0;
}
