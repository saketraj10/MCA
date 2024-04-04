#include<iostream>
using namespace std;
bool isCheck(int page, int frame[], int n){
    for(int i=0; i<n; i++){
        if(frame[i]==page) return true;
    }
    return false;
}

void display(int frame[], int n){
    for(int i=0; i<n; i++){
        if(frame[i]==-1) continue;
        cout<<frame[i]<<"\t";
    }
    cout<<endl;
}
int main()
{
    int f;
    cout<<"Enter the size of frame: ";
    cin>>f;

    int frame[f];
    for(int i=0; i<f; i++){
        frame[i] = -1;
    }

    int n;
    cout<<"Enter the size of reference string: ";
    cin>>n;
    int referenceString[n];
    cout<<"Enter the reference string: "<<endl;
    for(int i=0; i<n; i++){
        cin>>referenceString[i];
    }
    int hit=0;
    int k = 0;
    cout<<"Reference String\t";
    for(int i=0; i<f; i++){
        cout<<"Frame"<<(i+1)<<"\t";
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<referenceString[i]<<"\t\t\t";
        if(isCheck(referenceString[i], frame,f)){
            hit++;
            display(frame,f);
            continue;
        }
        int l=k%f;
        frame[l]=referenceString[i];
        display(frame,f);
        k++;
    }
    int pagefault = n-hit;
    cout<<"Total page fault: "<<pagefault<<endl;

    return 0;
}