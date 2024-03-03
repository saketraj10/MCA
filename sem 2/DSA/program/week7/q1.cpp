#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
class SortedLinkedList{
    private: 
    Node* head;
    public:
    SortedLinkedList(){
        head = NULL;
    }

    void insert(int value){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if(head==NULL || head->data >= value){
            newNode->next = head;
            head = newNode;
        }
        else{
            Node* current = head;
            while(current->next != NULL && current->next->data < value){
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void deleteNode(int value){
        Node* temp = head;
        Node* prev = NULL;
        if(temp!=NULL && temp->data==value){
            head = temp->next;
            delete temp;
            return;
        }
        while(temp!=NULL && temp->data!=value){
            prev = temp;
            temp = temp->next;
        }
        if(temp==NULL){
            return;
        }
        prev->next = temp->next;
        delete temp;
    }
    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){
    SortedLinkedList list;
    int ch, value;
    do
    {
        cout<<"1. Insert into Linkedlist"<<endl;
        cout<<"2. Delete from Linkedlist"<<endl;
        cout<<"3. Display the Linkedlist"<<endl;
        cout<<"Enter your choice, 0 to stop: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter the value to insert: ";
                cin>>value;
                list.insert(value);
                break;
            case 2:
                cout<<"Enter the value to delete: ";
                cin>>value;
                list.deleteNode(value);
                break;
            case 3:
                cout<<"Sorted Linked List: "<<endl;
                list.display();
                break;
            case 0:
                cout<<"Exit"<<endl;
                break;
            default:
                cout<<"Invalid choice, Please try again"<<endl;
        }
    }while(ch!=0);

    return 0;
}