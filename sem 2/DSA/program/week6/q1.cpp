//Implementation of Queue using arrays
//Saket Raj
//230970079
//19-02-2024
#include<iostream>
#include<cstring>
using namespace std;
class Queue
{
        char arr[100];
        int size;
        int front;
        int rear;
        int count;
        public:
        Queue(int s){
                size = s;
                front = -1;
                rear = -1;
                count = 0;
        }
        void enqueue(){
                if(rear == size - 1){
                        cout<<"Queue is overflow"<<endl;
                        return;
                }
		else{
                        if(front == -1)
                                front = 0;
                        char data;
                        cout<<"Enter the element in queue: ";
                        cin>>data;
                        count++;
                        arr[++rear] = data;
                }
        }
        char dequeue(){
                if(count==0){
                        return '@';
                }
                else{
                        count--;
                        return arr[front++];
                }
        }
        char queueFront(){
                if(count==0)
                        return '@';
                else
                        return arr[front];
        }
        int queueCount(){
                return count;
        }
	void displayQueue(){
                if(count==0)
                        cout<<"Queue is empty"<<endl;
                else{
                        cout<<"Queue elements are: "<<endl;
                        for(int i=front; i<=rear; i++)
                                cout<<arr[i]<<" ";
                        cout<<endl;
                }
        }
        void destroyQueue(){
                if(count==0)
                        cout<<"Queue is already empty"<<endl;
                else{

                        for(int i=front; i<=rear; i++)
                                dequeue();
                        cout<<"Queue is now destroy"<<endl;
                        front = -1;
                        rear = -1;
                }
        }
};
int main(){
        int n;
        cout<<"Enter the size of queue: ";
        cin>>n;
        Queue q1(n);
        int ch;
        do
	{
                cout<<"1. Insert into queue"<<endl;
                cout<<"2. Delete from queue"<<endl;
                cout<<"3. Display front element in the queue"<<endl;
                cout<<"4. Display the element in the queue"<<endl;
                cout<<"5. Destroy queue"<<endl;
                cout<<"Enter the following option, 0 for exit: ";
                cin>>ch;
		switch(ch)
                {
                        case 1:
                                q1.enqueue();
                                break;
                        case 2:
                                char y;
                                y = q1.dequeue();
                                if(y=='@')
                                        cout<<"Queue is underflow(or empty)"<<endl;
                                else
                                        cout<<"Deleted element is "<<y<<endl;
                                break;
                        case 3:
                                char x;
                                x = q1.queueFront();
                                if(x=='@')
                                        cout<<"Queue is empty"<<endl;
                                else
                                        cout<<"Front element is "<<x<<endl;
                                break;
                        case 4:
                                q1.displayQueue();
                                break;
                        case 5:
                                q1.destroyQueue();
                                break;
                        case 0: exit(0);
			default:
                                cout<<"Invalid choice, please enter again"<<endl;
                }
        }while(ch!=0);

        return 0;
}
			