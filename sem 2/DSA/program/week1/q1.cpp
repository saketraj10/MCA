//Obtain the Row-major and Column-major representation of the given input matrix.
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
                        cin>>matrix[i][j];
                }
        }
        cout<<endl;
        for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                        cout<<matrix[i][j]<<" ";
                }
                cout<<endl;
        }
        cout<<endl;
        int size = n*n;
        int arr[size];
        cout<<"row major : "<<endl;
        int k =0;
	for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                        arr[k] = matrix[i][j];
                        k++;
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
        if(x >= n || y >= n){
                cout<<"invalid x and y"<<endl;
                return 0;
        }
        int offset,value;
        offset = (x * n) + y;
        value = arr[offset];
        cout<<"offset = "<<offset<<endl;
        cout<<"value = "<<value<<endl;

        int arr1[size];
        k=0;
	cout<<"column major: "<<endl;
        for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                        arr1[k] = matrix[j][i];
                        k++;
                }
        }

        for(int i=0; i<size; i++){
                cout<<arr1[i]<<" ";
        }
        cout<<endl;
        cout<<"enter the value of x : "<<endl;
        cin>>x;
        cout<<"enter the value of y : "<<endl;
        cin>>y;
        if(x >= n || y >= n){
                cout<<"invalid x and y"<<endl;
                return 0;
        }

        offset = (y * n) + x;
        value = arr1[offset];
        cout<<"offset = "<<offset<<endl;
        cout<<"value = "<<value<<endl;

        return 0;
}