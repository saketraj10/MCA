#include<iostream>
using namespace std;
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

        bool flag = false;
        int low = 0;
        int high = n-1;
        while(low<=high)
        {
                int mid = low + (high-low)/2;
                if(arr[mid]==target){
                        flag = true;
                        break;
                }
                else if(arr[mid] > target) high = mid - 1;
                else low = mid + 1;
        }
	if(flag) cout<<target<<" is found in array"<<endl;
        else cout<<target<<" is not found in array"<<endl;

        return 0;
}