// Implement Bubble sort algorithm
// Saket Raj
// 230970079
// 11-03-2024
#include<iostream>
using namespace std;
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
        for(int i=0; i<n-1; i++)
        {
                bool flag = true;
                for(int j=0; j<n-1; j++)
                {
                        if(arr[j]>arr[j+1])
                        {
                                int temp = arr[j];
                                arr[j] = arr[j+1];
                                arr[j+1] = temp;
                                flag = false;
                        }
                }
                if(flag) break;
        }
	cout<<"Display array after bubble sort: "<<endl;
        for(int i=0; i<n; i++)
        {
                cout<<arr[i]<<" ";
        }
        cout<<endl;
        return 0;
}