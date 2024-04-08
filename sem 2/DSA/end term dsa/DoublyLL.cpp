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
class DoubleLL{
    private:
    Node* head;
    Node* tail;
    int size;
    public:
    DoubleLL(){
        head = tail = NULL;
        size = 0;
    }

    void insertAtTail(int val){
        Node* temp = new Node(val);
        if(size == 0) head = tail = temp;
        else{
            tail->next = temp;
            temp->prev = tail; //extra
            tail = temp;
        }
        size++;
    }
    
    void insertAtHead(int val){
        Node* temp = new Node(val);
        if(size==0) head = tail = temp;
        else{
            temp->next = head;
            head->prev = temp; //extra
            head = temp;
        }
        size++;
    }

    void insertAtIdx(int idx, int val){
        if(idx<0 || idx>size) cout<<"Invalid Index"<<endl;
        else if(idx==0) insertAtHead(val);
        else if(idx==size) insertAtTail(val);
        // else{
        //     Node* temp = new Node(val);
        //     Node* t = head;
        //     int count=1;
        //     while(t!=NULL){
        //         if(count==idx){
        //             temp->next = t->next;
        //             t->next = temp;
        //         }
        //         count++;
        //         t = t->next;
        //     }
        //     size++;
        // } 
        // or
        else{
            Node* t = new Node(val);
            Node* temp = head;
            for(int i=1; i<=idx-1; i++){
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            t->prev = temp; //extra
            t->next->prev = t; //extra
            size++;
        }
    }

    void insertWithSorted(int val){
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


    int getIdx(int idx){
        if(idx<0 || idx>=size) cout<<"Invalid index"<<endl;
        else if(idx==0) return head->val;
        else if(idx==size-1) return tail->val;
        else{
            Node* temp = head;
            for(int i=1; i<=idx; i++){
                temp = temp->next;
            }
            return temp->val;
        }
        return -1;
    }

    void deleteAtHead(){
        if(size==0){
            cout<<"List is empty"<<endl;
            return;
        }
        head = head->next;
        if(head!=NULL) head->prev = NULL; //extra
        if(head==NULL) tail = NULL; //extra
        size--;
    }

    void deleteAtTail(){
        if(size==0){
            cout<<"List is empty"<<endl;
            return;
        }
        else if(size==1){ //extra
            deleteAtHead();
            return;
        }
        //extra
        Node* temp = tail->prev;
        temp->next = NULL;
        tail = temp;
        size--;
    }
    
    
    void deleteAtIdx(int idx){
        if(size==0){
            cout<<"List is empty"<<endl;
            return;
        }
        if(idx<0 || idx>=size) cout<<"Invalid index"<<endl;
        else if(idx==0) deleteAtHead();
        else if(idx==size-1) deleteAtTail();
        else{
            Node* temp = head;
            for(int i=1; i<=idx-1; i++){
                temp = temp->next;
            }
            temp->next = temp->next->next;
            temp->next->prev = temp; //extra
            size--;
        }
    }

    void deleteWithValue(int value){
        if(size==0){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp = head;
        int idx = -1;
        int i=0;
        while(temp!=NULL){
            if(temp->val==value){
                idx = i;
                break;
            }
            i++;
            temp = temp->next;
        }
        if(idx==-1) cout<<"Incorrect value"<<endl;
        else deleteAtIdx(idx);
    }

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    int midElement(){
        Node* temp  = head;
        Node* mid = head;
        int count = 1;
        while(temp!=NULL){
            if(count%2==0){
                mid = mid->next;
            }
            temp = temp->next;
            count++;
        }
        return mid->val;
    }

    void reversedisplay(Node* temp){
        if(temp==NULL) return;
        reversedisplay(temp->next);
        cout<<temp->val<<" ";
    }

    void reverse(){
        if(size==0){
            cout<<"List is empty"<<endl;
        }
        reversedisplay(head);
        cout<<endl;
    }
};

int main(){

    DoubleLL dll;
    dll.insertAtTail(30);
    dll.insertAtTail(60);
    dll.insertAtTail(70);
    dll.display();
    dll.insertAtHead(50);
    dll.display();
    dll.insertAtIdx(2,45);
    dll.display();
    dll.deleteAtTail();
    dll.display();
    dll.deleteAtHead();
    dll.display();
    dll.insertAtIdx(2,58);
    dll.display();
    dll.deleteAtIdx(1);
    dll.display();
    cout<<dll.getIdx(1)<<endl;

    return 0;
}