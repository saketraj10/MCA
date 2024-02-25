//Implementation of Circular Queue using arrays
//Saket Raj
//230970079
//19-02-2024
#include<iostream>
using namespace std;
class CircularQueue
{
    int size, front, rear, count;
    int* arr;
    public:
    CircularQueue(int s){
        size = s;
        arr = new int[size];
        front=0;
        rear=0;
        count = 0;
    }
    bool isFull(){
        return count==size;
    }
    bool isEmpty(){
        return count==0;
    }

    void enqueue(int ele){
        if(isFull()){
            cout<<"Circular queue is full (overflow)"<<endl;
            return;
        }
        else{
            arr[rear]=ele;
            rear = (rear+1)%size;
            count++;
        }
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Circular queue is empty (underflow)"<<endl;
            return;
        }
        else{
            cout<<"Deleted element is "<<arr[front]<<endl;
            front = (front+1)%size;
            count--;
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"Circular queue is empty (underflow)"<<endl;
            return;
        }
        else{
            cout<<"Display circular queue are: "<<endl;
            for(int i=0; i<count; i++){
                cout<<arr[(i+front)%size]<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    int s;
    cout<<"Enter the size of circular queue: ";
    cin>>s;
    CircularQueue q1(s);
    int ch;
    do{
        cout<<"1. Insert into circular queue"<<endl;
        cout<<"2. Delete from circular queue"<<endl;
        cout<<"3. Display the element"<<endl;
        cout<<"Enter your choice, 0 to exit: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                int ele;
                cout<<"Enter the element in circular queue: ";
                cin>>ele;
                q1.enqueue(ele);
                break;
            case 2:
                q1.dequeue();
                break;
            case 3:
                q1.display();
                break;
            case 0: exit(0);
            default:
                cout<<"Invalid choice, please enter correct choice: "<<endl;
        }
    }while(ch!=0);
    return 0;
}