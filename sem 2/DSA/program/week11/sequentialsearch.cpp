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
        for(int i=0; i<n; i++)
        {
                if(arr[i]==target)
                {
                        flag = true;
                        break;
                }
        }
        if(flag) cout<<target<<" is found in array"<<endl;
        else cout<<target<<" is not found in array"<<endl;

        return 0;
}