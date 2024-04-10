#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class AdjList{
    public:
    Node* head;
};

class Graph{
    private:
    int v;
    AdjList* arr;
    public:
    Graph(int v){
        this->v = v;
        arr = new AdjList[v];
        for(int i=0; i<v; i++){
            arr[i].head = NULL;
        }
    }

    void addEdge(int src, int dest){
        Node* temp = new Node(dest);
        temp->next = arr[src].head;
        arr[src].head = temp;

        temp = new Node(src);
        temp->next = arr[dest].head;
        arr[dest].head = temp;
    }

    void display(){
        for(int i=0; i<v; i++){
            Node* root = arr[i].head;
            cout<<"Adjacency list of vertex "<<i<<endl;
            while(root!=NULL){
                cout<<root->val<<" -> ";
                root = root->next;
            }
            cout<<endl;
        }
    }
};
int main(){
    int n;
    cout<<"Enter the no of vertices: ";
    cin>>n;
    Graph g1(n);

    int e;
    cout<<"Enter the no of edges: ";
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

    cout<<"Display Adjacency list of graph: "<<endl;
    g1.display();

    return 0;
}