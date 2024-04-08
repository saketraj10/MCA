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

class Stack{
    private:
    Node* head;
    int size;
    public:
    Stack(){
        head = NULL;
        size = 0;
    }

    void push(int val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void pop(){
        if(size==0){
            cout<<"Stack is empty, underflow"<<endl;
            return;
        }
        head = head->next;
        size--;
    }

    int top(){
        if(size==0){
            cout<<"Stack is empty, underflow"<<endl;
            return -1;
        }
        return head->val;
    }

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<endl;
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Stack s;
    s.push(1);
    s.push(4);
    s.push(2);
    s.push(67);
    s.push(54);

    s.display();
    cout<<s.top()<<endl;
    cout<<endl;
    s.pop();
    s.display();
}