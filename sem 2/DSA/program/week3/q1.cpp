//Solving problems using Recursion Tower of Hanoi for n disks
//Saket Raj
//230970079
//22-01-2024
#include<iostream>
using namespace std;
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod){
        if(n==0){
                return;
        }
        towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
        cout<<"Move disk "<<n<<" from rod "<<from_rod<<" to rod "<<to_rod<<endl;
        towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}
int main(){
        int n;
        cout<<"enter the number of disks: ";
        cin>>n;

        //A means source, D means destination and B means Auxiliary
        towerOfHanoi(n, 'A', 'D', 'B');

        return 0;
}