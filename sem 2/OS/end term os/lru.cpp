#include<iostream>
using namespace std;
bool isCheck(int page, int frame[], int f)
{
    for(int i=0; i<f; i++)
    {
        if(frame[i]==page) return true;
    }
    return false;
}

void display(int frame[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(frame[i]==-1) continue;
        cout<<frame[i]<<"\t";
    }
    cout<<endl;
}

int findLeastUsed(int referenceString[], int frame[], int f, int id)
{
    int idx = 0;
    int minLastUsed = id;
    for(int i=0; i<f; i++)
    {
        for(int j=id-1; j>=0; j--)
        {
            if(frame[i] == referenceString[j])
            {
                if(j<minLastUsed)
                {
                    minLastUsed = j;
                    idx = i;
                }
                break;
            }
        }
    }
    return idx;
}
int main()
{
    int f;
    cout<<"Enter the size of frame: ";
    cin>>f;
    int frame[f];
    for(int i=0; i<f; i++)
    {
        frame[i] = -1;
    }

    int n;
    cout<<"Enter the size of reference string: ";
    cin>>n;
    int referenceString[n];
    cout<<"Enter the reference string: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>referenceString[i];
    }
    int hit = 0;
    cout<<"Reference string\t";
    for(int i=0; i<f; i++)
    {
        cout<<"Frame"<<i+1<<"\t";
    }
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<referenceString[i]<<"\t\t\t";
        if(isCheck(referenceString[i],frame,f)){
            hit++;
            display(frame,f);
            continue;
        }
        else if(i<f)
        {
            frame[i] = referenceString[i];
            display(frame,f);
        }
        else
        {
            int idx = findLeastUsed(referenceString, frame, f, i);
            frame[idx] = referenceString[i];
            display(frame,f);
        }
    }
    int pagefault = n-hit;
    cout<<"Total page fault: "<<pagefault<<endl;

    return 0;
}