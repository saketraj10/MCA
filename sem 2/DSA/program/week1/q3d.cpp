//Map the following 2-D arrays (matrices) to 1-D arrays (lists) of Lower triangular matrix
//Saket Raj
//230970079
//08-01-2023
#include<iostream>
using namespace std;
int main(){
        int n;
        cout<<"enter the size of square matrix: "<<endl;
        cin>>n;
        int matrix[n][n];
        cout<<"enter the element of square matrix: "<<endl;
        for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                        if(i >= j)
                                cin>>matrix[i][j];
                        else
                                matrix[i][j] = 0;
                }
        }
        cout<<endl;
        for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                        cout<<matrix[i][j]<<" ";
                }
                cout<<endl;
        }
        int size = n * (n+1) /2;
        int arr[size];
        int k=0;
	 for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                        if(i >= j){
                                arr[k] = matrix[i][j];
                                k++;
                        }
                }
        }
        for(int i=0; i<size; i++){
                cout<<arr[i]<<" ";
        }
        cout<<endl;
        int x,y;
        cout<<"enter the value of x: "<<endl;
        cin>>x;
        cout<<"enter the value of y: "<<endl;
        cin>>y;
        if(x >= n || y >= n || x<y){
                cout<<"invalid x and y"<<endl;
                return 0;
        }
        int offset,value;
        offset = (x*(x+1)/2 + y);
        value = arr[offset];
        cout<<"offset = "<<offset<<endl;
        cout<<"value = "<<value<<endl;
        return 0;
}