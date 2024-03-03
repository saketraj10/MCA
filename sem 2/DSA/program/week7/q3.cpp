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
class Stack
{
    private:
    Node* head;
    int size;
    public:
    Stack(){
        head = NULL;
        size = 0;
    }
    void push(int val){
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        size++;
    }
    void pop(){
        if(head==NULL){
            cout<<"Stack is empty"<<endl;
            return;
        }
        cout<<"Deleted value: "<<head->val<<endl;
        head = head->next;
        size--;
    }
    int top(){
        if(head==NULL){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return head->val;
    }
    void print(Node* temp){
        if(temp==NULL) return;
        cout<<temp->val<<endl;
        print(temp->next);
    }
    void display()
    {   
        if(head==NULL){
            cout<<"Stack is empty"<<endl;
            return;
        }
        print(head);
    }
};
int main()
{
    Stack s;
    int ch;
    do{
        cout<<"1. Push into stack"<<endl;
        cout<<"2. Pop from stack"<<endl;
        cout<<"3. Display top element in stack"<<endl;
        cout<<"4. Display stack"<<endl;
        cout<<"Enter your choice, 0 to stop: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                int val;
                cout<<"Enter the value to insert: ";
                cin>>val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                if(s.top()!=-1){
                    cout<<"Top element: "<<s.top()<<endl;
                }
                break;
            case 4:
                cout<<"Display Stack: "<<endl;
                s.display();
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