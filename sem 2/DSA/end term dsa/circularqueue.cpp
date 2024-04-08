#include<iostream>
#include<cstring>
#include<string>
using namespace std;
class Circularqueue
{
    private:
    char* arr;
    int size, front, rear, count;
    public:
    Circularqueue(int size)
    {
        this->size = size;
        front = rear = 0;
        count = 0;
        arr = new char[size];
    }

    bool isEmpty(){
        return count==0;
    }
    bool isFull(){
        return count==size;
    }

    void enqueue(char data){
        if(isFull()){
            cout<<"Circular queue is full, overflow"<<endl;
            return;
        }
        arr[rear] = data;
        rear = (rear+1)%size;
        count++;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Circular queue is empty, underflow"<<endl;
            return;
        }
        arr[front] = 0;
        front = (front+1)%size;
        count--;
    }

    char getFront(){
        if(isEmpty()){
            cout<<"Circular queue is empty, underflow"<<endl;
            return ' ';
        }
        return arr[front];
    }

    char getRear(){
        if(isEmpty()){
            cout<<"Circular queue is empty, underflow"<<endl;
            return ' ';
        }
        return arr[rear];
    }

    void display(){
        if(isEmpty()){
            cout<<"Circular queue is empty, underflow"<<endl;
            return;
        }
        for(int i=0; i<count; i++){
            cout<<arr[(i+front)%size]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    int n;
    cout<<"enter the size of character array: ";
    cin>>n;

    Circularqueue cq1(n);
    char arr[n];
    cin.ignore();
    cout<<"enter the character: "<<endl;
    //cin>>arr;
    //cin.get(arr,n);
    cin.getline(arr,n, ' ');
    cin.ignore();

    for(int i=0; arr[i]!='\0'; i++){
        cq1.enqueue(arr[i]);
    }
    cout<<endl;
    cq1.display();
    cq1.dequeue();
    cout<<cq1.getFront()<<endl;
    cout<<cq1.getRear()<<endl;
    cq1.dequeue();
    cq1.dequeue();
    cq1.display();


    return 0;
}