#include<iostream>
using namespace std;
bool binarySearch(int arr[], int low, int high, int target)
{
        if(low<=high)
        {
                int mid = low + (high-low)/2;
                if(arr[mid]==target){
                        return true;
                }
                else if(arr[mid] > target)
                {
                        return binarySearch(arr,low,mid-1, target);
                }
                else
                        return binarySearch(arr,mid+1,high, target);
        }
        return false;
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
        int target;
        cout<<"Enter the target value: ";
        cin>>target;

        int low = 0;
        int high = n-1;

        bool flag = binarySearch(arr,low,high,target);

        if(flag) cout<<target<<" is found in array"<<endl;
        else cout<<target<<" is not found in array"<<endl;

        return 0;
}