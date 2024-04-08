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
class Queue{
    private:
    Node* head;
    Node* tail;
    int size;
    public:
    Queue(){
        head = tail = NULL;
        size = 0;
    }

    void enqueue(int val){
        Node* temp = new Node(val);
        if(size==0) head = tail = temp;
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void dequeue(){
        if(size==0){
            cout<<"Queue is empty, overflow"<<endl;
            return;
        }
        head = head->next;
        size--;
    }

    int front(){
        if(size==0){
            cout<<"Queue is empty, overflow"<<endl;
            return -1;
        }
        return head->val;
    }

    int rear(){
        if(size==0){
            cout<<"Queue is empty, overflow"<<endl;
            return -1;
        }
        return tail->val;
    }

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Queue q1;
    q1.enqueue(3);
    q1.enqueue(42);
    q1.enqueue(23);
    q1.enqueue(38);

    q1.display();
    cout<<q1.front()<<endl;
    cout<<q1.rear()<<endl;
    q1.dequeue();
    q1.display();

    return 0;
}