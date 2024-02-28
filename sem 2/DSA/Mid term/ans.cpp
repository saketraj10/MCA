#include<iostream>
#include<cstring>
#include<string>
using namespace std;
class Stack
{
        char *arr;
        int size, count;
        public:
        Stack(int s)
        {
                size = s;
                arr = new char[s];
                count = -1;
        }
        void push(char a){
                if(count==size-1)
                        cout<<"Stack is full"<<endl;
                else{
                        arr[++count] = a;
                }
        }
        char top(){
                if(!empty()){
                        return arr[count];
                }
                return '\0';
        }
        void pop(){
                if(!empty())
                        arr[--count];
        }
        bool empty()
        {
                if(count==-1)
                        return true;
                else
                        return false;
        }
        void display(){
                if(empty())
                        cout<<"stack is empty"<<endl;
                else{
                        for(int i=0; i<=count; i++)
                                cout<<arr[i];
                }
        }
        int getCount(){
                return size;
        }

};
bool ischeck(Stack s1){
        int n = s1.getCount();
        Stack s2(n);
        Stack s3 = s1;
        Stack s4 = s1;
        while(!s3.empty())
        {
                s2.push(s3.top());
                s3.pop();
        }
        while(!s4.empty()){
                if(s4.top()!=s2.top())
                        return false;
                s2.pop();
                s4.pop();
        }
        return true;
}
int main()
{
        int n;
        cout<<"Enter the size of stack: "<<endl;
        cin>>n;
        cin.ignore();
        Stack s1(n);
        char w[100],wr[100];
        cout<<"enter w value: ";
        cin.get(w,100);
        cin.ignore();
        cout<<"enter wr value: ";
        cin.get(wr,100);
        for(int i=0; w[i]!='\0'; i++)
        {
                s1.push(w[i]);
        }
        s1.push('c');
        for(int i=0; wr[i]!='\0'; i++)
        {
                s1.push(wr[i]);
        }

        if(ischeck(s1)){
                cout<<"The string is ";
                s1.display();
                cout<<", Display->valid string "<<endl;
        }
        else{
                cout<<"The string is ";
                s1.display();
                cout<<", Display-> invalid becoz w="<<w<<" "<<"wr = "<<wr<<endl;
        }
        return 0;
}