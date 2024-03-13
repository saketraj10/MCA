// Implement Selection sort algorithm
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
                int min = i;
                for(int j = i+1; j<n; j++)
                {
                        if(arr[j] < arr[min])
                        {
                                min = j;
                        }
                }
                int temp = arr[min];
                arr[min] = arr[i];
                arr[i] = temp;
        }
	
        cout<<"Display array after selection sort: "<<endl;
        for(int i=0; i<n; i++)
        {
                cout<<arr[i]<<" ";
        }
        cout<<endl;
        return 0;
}