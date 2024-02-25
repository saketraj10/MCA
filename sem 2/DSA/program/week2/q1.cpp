//Represent a sparse matrix using 1-D array. Use this 1-D array to reconstruct the original matrix
//Saket Raj
//230970079
//15-01-2023
#include<iostream>
using namespace std;
struct sparce{
        int row;
        int col;
        int value;
};
int main(){
        int r,c;
        cout<<"enter the row of matrix: ";
        cin>>r;
        cout<<"enter the col of matrix: ";
        cin>>c;
        int matrix[r][c];
        cout<<"enter the element of sparse matrix: "<<endl;
        for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                        cin>>matrix[i][j];
                }
        }
        cout<<endl;
	int count = 0;
        for(int i=0; i<r;i++){
                for(int j=0; j<c;j++){
                        if(matrix[i][j] != 0){
                                count++;
                        }
                }
        }
        int size = count + 1;
        sparce s[size];

        s[0].row = r;
        s[0].col = c;
        s[0].value = count;

        int k=1;
        for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                        if(matrix[i][j] != 0){
                                s[k].row = i;
                                s[k].col = j;
                                s[k].value = matrix[i][j];
                                k++;
                        }
                }
        }
        cout<<"sparce matrix in 1-D array: "<<endl;
	for(int i=1; i<size; i++){
                cout<<s[i].value<<" ";
        }
        cout<<endl;

        int x,y;
        x = s[0].row;
        y = s[0].col;



        int matrix1[x][y];
        int p=1;
        for(int i=0; i<x; i++){
                for(int j=0; j<y; j++){
                        if(s[p].row == i && s[p].col ==j){
                               matrix1[i][j] = s[p].value;
                               p++;
                        }
                        else{
                                matrix1[i][j] = 0;
                        }
                }
        }

        cout<<"display the sparse matrix form 1-D array: "<<endl;
	for(int i=0; i<x; i++){
                for(int j=0; j<y; j++){
                        cout<<matrix1[i][j]<<" ";
                }
                cout<<endl;
        }
        cout<<endl;
        return 0;
}