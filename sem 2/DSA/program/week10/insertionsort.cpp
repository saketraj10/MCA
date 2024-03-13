// Implement Insertion sort algorithm
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

        for(int i=1; i<n; i++)
        {
                int key = arr[i];
                int j = i-1;
                while(j>=0 && key < arr[j])
                {
                        arr[j+1] = arr[j];
                        j--;
                }
                arr[j+1] = key;
        }
	
	cout<<"Display array after insertion sort: "<<endl;
        for(int i=0; i<n; i++)
        {
                cout<<arr[i]<<" ";
        }
        cout<<endl;
        return 0;
}