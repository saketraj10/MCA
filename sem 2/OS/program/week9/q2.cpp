#include<iostream>
using namespace std;
bool isCheck(bool processCompletion[], int l)
{
        if(processCompletion[l]==false) return true;
        return false;
}
int main()
{
        int n,r;
        cout<<"Enter the no of processes: ";
        cin>>n;
        cout<<"Enter the no of resources: ";
        cin>>r;
        int totalr[r];
        cout<<"Enter the total resources: ";
        for(int i=0; i<r; i++)
        {
                cin>>totalr[i];
        }
        int p[n];
        int allocr[n][r];
        int maxr[n][r];
        cout<<"Enter the process id ( in int ), allocatted resources, maximum resources required: "<<endl;
        for(int i=0; i<n; i++)
        {
                cout<<"Enter process id: ";
                cin>>p[i];
                cout<<"Enter the "<<r<<" allocated recources: ";
                for(int j=0; j<r; j++)
                {
                        cin>>allocr[i][j];
                }
                cout<<"Enter the "<<r<<" maximum resources required: ";
                for(int j=0; j<r; j++)
                {
                        cin>>maxr[i][j];
                }
        }
        cout<<endl;

        int available[r];
        for(int i=0; i<r; i++)
        {
                int to = 0;
                for(int j=0; j<n; j++)
                {
                        to += allocr[j][i];
                }
                available[i] = totalr[i] - to;
        }
        for(int i=0; i<r; i++)
        {
                if(available[i]<0)
                {
                        cout<<"Allocation of resources can't be exceed the maximum"<<endl;
                        return 0;
                }
        }
        int need[n][r];
        for(int i=0; i<n; i++)
        {
                for(int j=0; j<r; j++)
                {
                        need[i][j] = maxr[i][j] - allocr[i][j];
                }
        }
        bool processCompletion[n];
        for(int i=0; i<n; i++)
        {
                processCompletion[i] = false;
        }
        int round = 0;
        int l = 0;
        int sequenceP[n];
        int k= 0;
        while(round <= n*n)
        {
                if(l==n) l=0;
                if(isCheck(processCompletion,l))
                {
                        bool flag = true;
                        for(int i=0; i<r; i++)
                        {
                                if(need[l][i]>available[i]) flag = false;
                        }
                        if(flag)
                        {
                                for(int i=0; i<r; i++)
                                {
                                        available[i] += allocr[l][i];
                                        allocr[l][i] = 0;
                                }
                                sequenceP[k] = p[l];
                                k++;
                                processCompletion[l] = true;
                        }
                }
                round++;
                l++;
        }

        bool safe = true;
        for(int i=0; i<r; i++)
        {
                int to = 0;
                for(int j=0; j<n; j++)
                {
                        to += allocr[j][i];
                }
                if(to!=0)
                {
                        safe = false;
                        break;
                }
        }
        if(safe)
        {
                cout<<"System is in safe state"<<endl;
                cout<<"Safe sequence : "<<endl;
                for(int i=0; i<n; i++)
                {
                        cout<<sequenceP[i]<<" ";
                }
                cout<<endl;
        }
        else
        {
                cout<<"System is not in safe state"<<endl;
        }
        return 0;
}