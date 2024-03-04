#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
class Queue
{
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
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Deleted value: "<<head->val<<endl;
        head = head->next;
        size--;
    }
    int front(){
        if(size==0){
        cout<<"Queue is empty"<<endl;
            return -1;
        }
        return head->val;
    }
    int back(){
        if(size==0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return tail->val;
    }
    void display()
    {   
        if(size==0){
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    Queue q;
    int ch;
    do{
        cout<<"1. Enqueue into Queue"<<endl;
        cout<<"2. Dequeue from Queue"<<endl;
        cout<<"3. Display front element in Queue"<<endl;
        cout<<"4. Display back element in Queue"<<endl;
        cout<<"5. Display Queue"<<endl;
        cout<<"Enter your choice, 0 to stop: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                int val;
                cout<<"Enter the value to insert: ";
                cin>>val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                if(q.front()!=-1){
                    cout<<"Front element: "<<q.front()<<endl;
                }
                break;
            case 4:
                if(q.back()!=-1){
                    cout<<"Back element: "<<q.back()<<endl;
                }
                break;
            case 5:
                cout<<"Display Queue: "<<endl;
                q.display();
                break;
            case 0:
                cout<<"Exit"<<endl;
                break;
            default:
                cout<<"Invalid choice, please enter again"<<endl;
        }
    }while(ch!=0);
    return 0;
}