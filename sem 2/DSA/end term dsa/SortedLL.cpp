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
class SortedLinkedList{
    private:
    Node* head;
    int size;
    public:
    SortedLinkedList(){
        head = NULL;
        size = 0;
    }

    void insert(int val){
        Node* t = new Node(val);

        if(head==NULL || head->val >= val){
            t->next = head;
            head = t;
            size++;
            return;
        }
        else{
            Node* temp = head;
            while(temp->next!=NULL && temp->next->val < val){
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }

    void insertAtTail(int val){
        Node* t = new Node(val);
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = t;
        size++;
    }

    void deleteNode(int val){
        if(size==0){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
    }

    void reverse(){
        head = reverseList(head);
    }

    Node* reverseList(Node* head){
        Node* prev = NULL;
        Node* temp = head;
        while(temp!=NULL){
            Node* nextTemp = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextTemp;
        }
        return prev;
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
int main()
{
    SortedLinkedList ll;
    ll.insert(10);
    ll.insert(50);
    ll.insert(30);
    ll.insert(15);
    ll.display();

    ll.insertAtTail(100);
    ll.display();

    ll.reverse();
    ll.display();
    return 0;
}