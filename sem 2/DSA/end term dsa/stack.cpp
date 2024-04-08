#include<iostream>
#include<cstring>
using namespace std;
class Stack
{
    private:
    int size;
    char* arr;
    int count;
    public:
    Stack(int s){
        this->size = s;
        arr = new char[size];
        count = 0;
    }
    
    bool isEmpty(){
        return count==0;
    }
    bool isFull(){
        return count==size;
    }
    void push(char data){
        if(isFull()){
            cout<<"Stack is full, overflow"<<endl;
            return;
        }
        arr[count++] = data;
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty, underflow"<<endl;
            return;
        }
        arr[count--] = 0;
    }

    char top(){
        if(isEmpty()){
            cout<<"Stack is empty, underflow"<<endl;
            return ' ';
        }
        return arr[count];
    }
    
    void display()
    {
        if(isEmpty()){
            cout<<"Stack is empty, underflow"<<endl;
            return;
        }
        for(int i=count-1; i>=0; i--){
            cout<<arr[i]<<endl;
        }
    }

    void destroy(){
        if(isEmpty()){
            cout<<"Stack is already empty"<<endl;
            return;
        }
        for(int i=count-1; i>=0; i--){
            arr[i]=0;
            count--;
        }
        cout<<"Stack is now empty"<<endl;
    }
};
int main()
{
    Stack s(10);
    char c;
    cout<<"Enter a character: ";
    cin>>c;
    
    cin.ignore();

    //cin.get(c);
    //c = getchar();
    //gets(c);
    s.push(c);
    s.push('s');
    s.push('a');
    s.push('k');
    s.push('e');
    s.push('t');
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<endl;
    s.display();
    s.destroy();
    s.display();

}