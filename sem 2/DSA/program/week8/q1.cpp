// Implement a sorted doubly linked list. Include the following options: inserting a node, deleting a node and displaying the list in both directions.
// Saket Raj
// 230970079
// 04-03-2024
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class SortedDoublyLinkedList{
    private:
    Node* head;
    Node* tail;
    public:
    SortedDoublyLinkedList(){
        head = tail = NULL;
    }

    void insert(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = tail = newNode;
            return;
        }
        if(val<head->val){
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }
        Node* current = head;
        while(current->next && current->next->val < val){
            current = current->next;
        }
        newNode->next = current->next;
        if(current->next){
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
        if(!newNode->next){
            tail = newNode;
        }
    }

    void deleteNode(int val){
        if(!head){
            return;
        }
        Node* current = head;

        if(head->val==val){
            head = head->next;
            if(head){
                head->prev = NULL;
            }
            if(!head){
                tail = NULL;
            }
            delete current;
            return;
        }
        
        while(current && current->val != val){
            current = current->next;
        }
        if(!current){
            return;
        }

        if(current->prev){
            current->prev->next = current->next;
        }
        if(current->next){
            current->next->prev = current->prev;
        }
        if(current==tail){
            tail = current->prev;
        }
        delete current;
    }
    void displayForward(){
        if(!head){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* current = head;
        while(current){
            cout<<current->val<<" ";
            current = current->next;
        }
        cout<<endl;
    }

    void displayBackward(){
        if(!head){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* current = tail;
        while(current){
            cout<<current->val<<" ";
            current = current->prev;
        }
        cout<<endl;
    }
};

int main(){
    SortedDoublyLinkedList list;
    int ch;
    do{
        cout<<"1. Insert into DoublyLinkedList"<<endl;
        cout<<"2. Delete from DoublyLinkedList"<<endl;
        cout<<"3. Display the List from forward direction"<<endl;
        cout<<"4. Display the List from Backward direction"<<endl;
        cout<<"Enter your choices, 0 to stop: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                int val;
                cout<<"Enter the value to insert: ";
                cin>>val;
                list.insert(val);
                break;
            case 2:
                int del;
                cout<<"Enter the value to delete: ";
                cin>>del;
                list.deleteNode(del);
                break;
            case 3: 
                cout<<"Display List in forward direction: "<<endl;
                list.displayForward();
                break;
            case 4:
                cout<<"Display List in backward direction: "<<endl;
                list.displayBackward();
                break;
            case 0: 
                cout<<"Exit"<<endl;
                break;
            default:
                cout<<"Invalid choice, please enter again"<<endl;
        }
    }while(ch!=0);
    
}