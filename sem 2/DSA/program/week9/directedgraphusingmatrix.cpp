#include<iostream>
using namespace std;
class DirectedGraphUsingMatrix
{
    private:
    int size;
    int** matrix;
    public:
    DirectedGraphUsingMatrix(int size){
        this->size = size;
        matrix = new int*[size];
        for(int i=0; i<size; i++){
            matrix[i] = new int[size];
        }

        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                matrix[i][j] = 0;
            }
        }
    }

    void addEdge(int s, int d){
        matrix[s-1][d-1] = 1;
    }

    void display(){
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"Enter the no node: ";
    cin>>n;

    DirectedGraphUsingMatrix g1(n);
    
    int e;
    cout<<"Enter the no edge: ";
    cin>>e;
    cout<<"Enter the edge value: "<<endl;
    for(int i=0; i<e; i++){
        cout<<"Enter "<<i+1<<" edge: "<<endl;
        int source, destination;
        cout<<"Enter source node: ";
        cin>>source;
        cout<<"Enter the destination node: ";
        cin>>destination;
        g1.addEdge(source,destination);
    }

    cout<<"Display adjacency matrix: "<<endl;
    g1.display();


    return 0;
}