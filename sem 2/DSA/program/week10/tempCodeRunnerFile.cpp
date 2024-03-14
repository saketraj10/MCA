// Implement Quick sort algorithm
// Saket Raj
// 230970079
// 11-03-2024

#include<iostream>
using namespace std;
int partition(int arr[], int low, int high)
{
        int key = arr[low];
        int i = low + 1;
        int j = high;
        while(i<=j)
        {
                while(i<=high && key >= arr[i]) i++;
                while(key<arr[j]) j--;
                if(i<j)
                {
                        int temp  = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                }
                else{
                        int temp = arr[low];
                        arr[low] = arr[j];
                        arr[j] = temp;
                }
        }
        return j;
}
void quickSort(int arr[], int low, int high)
{
        if(low<high)
        {
                int mid = partition(arr,low,high);
                quickSort(arr, low, mid-1);
                quickSort(arr, mid+1, high);
        }
}
int main()
{
        int n;
        cout<<"Enter the size of array: ";
        cin>>n;
        int arr[n];
        cout<<"Enter the element of array: "<<endl;
        for(int i=0; i<n; i++)
        {
                cin>>arr[i];
        }
        quickSort(arr,0,n-1);

        cout<<"Display array after quicksort: "<<endl;
        for(int i=0; i<n; i++)
        {
                cout<<arr[i]<<" ";
        }
        cout<<endl;
        return 0;
}