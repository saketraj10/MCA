#include<iostream>
using namespace std;
void merge(int a[], int lo, int mid, int hi){
    int i=lo;
    int j=mid+1;
    int k=lo;
    int b[hi+1];
    while(i<=mid && j<=hi){
        if(a[i]<a[j]){
            b[k] = a[i];
            i++;
        }
        else{
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        b[k] = a[i];
        i++;
        k++;
    }
    while(j<=hi){
        b[k] = a[j];
        j++;
        k++;
    }
    for(int i=lo; i<=hi; i++){
        a[i] = b[i];
    }
}
void mergeSort(int a[], int lo, int hi){
    if(lo<hi){
        int mid = (lo+hi)/2;
        mergeSort(a,lo,mid);
        mergeSort(a,mid+1,hi);
        
        merge(a,lo,mid,hi);
    }
}
int main()
{
    int n; 
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the element of array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    mergeSort(arr,0,n-1);
    cout<<"Display after sorted: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}