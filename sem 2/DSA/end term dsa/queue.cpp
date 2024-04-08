#include<iostream>
using namespace std;
class Queue{
    private:
    int size;
    char* arr;
    int front, rear, count;
    public:
    Queue(int s){
        this->size = s;
        front = rear = -1;
        count = 0;
        arr = new char[size];
    }
    bool isEmpty(){
        return count==0;
    }
    bool isFull(){
        return rear==size-1;
    }

    void enqueue(char data){
        if(isFull()){
            cout<<"Queue is full, overflow"<<endl;
            return;
        }
        if(front==-1) front = 0;
        arr[++rear] = data;
        count++;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty, underflow"<<endl;
            return;
        }
        arr[front] = 0;
        front++;
        count--;
    }

    char getFront(){
        if(isEmpty()){
            cout<<"Queue is empty, underflow"<<endl;
            return ' ';
        }
        return arr[front];
    }

    char getRear(){
        if(isEmpty()){
            cout<<"Queue is empty, underflow"<<endl;
            return ' ';
        }
        return arr[rear];
    }

    void display(){
        if(isEmpty()){
            cout<<"Queue is empty, underflow"<<endl;
            return;
        }
        for(int i=front; i<=rear; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void destroy(){
        if(isEmpty()){
            cout<<"Queue is empty, underflow"<<endl;
            return;
        }
        for(int i=0; i<count; i++){
            dequeue();
        }
        cout<<"Queue is now empty"<<endl;
        rear = -1;
        front = -1;
    }
};
int main(){
    Queue q1(10);

    char c;
    cout<<"enter a queue: ";
    cin>>c;
    cin.ignore();

    q1.enqueue(c);
    q1.enqueue('s');
    q1.enqueue('a');
    q1.enqueue('b');
    q1.enqueue('c');
    q1.display();
    cout<<endl;
    cout<<q1.getFront()<<endl;
    cout<<q1.getRear()<<endl;
    q1.dequeue();
    cout<<endl;
    cout<<q1.getFront()<<endl;
    cout<<q1.getRear()<<endl;
    cout<<endl;
    q1.display();
    q1.destroy();
    cout<<q1.getFront()<<endl;
    cout<<q1.getRear()<<endl;
    q1.display();
    q1.enqueue(c);
    q1.display();
    cout<<q1.getFront()<<endl;
    cout<<q1.getRear()<<endl;


    return 0;
}