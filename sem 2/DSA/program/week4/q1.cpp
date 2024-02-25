//Implemention of stack using arrays
//Saket Raj
//230970079
//05-02-2023
#include<iostream>
using namespace std;
class stack{
        private:
        int count;
        int size;
        char arr[100];
        public:
        stack(int n){
                size = n;
                count = 0;
        }
        bool isFullStack(){
                if(count==size)
                        return true;
                else
                        return false;
        }
        void pushStack(char data){
                if(isFullStack())
                        cout<<"Stack is full, overflow"<<endl;
                else
                        arr[count++] = data;
        }

        bool isEmptyStack(){
                if(count==0)
                        return true;
                else
                        return false;
        }
	void popStack(){
                if(isEmptyStack())
                        cout<<"Stack is empty, underflow"<<endl;
                else{
                        cout<<"The popped element is "<<arr[--count]<<endl;
                }
        }
        int stackCount(){
                return count;
        }
        void destroyStack(){
                if(isEmptyStack())
                        cout<<"stack is destroy"<<endl;
                else{
                        for(int i=stackCount(); i>0; i--){
                                arr[i]=0;
                                count--;
                        }
                        cout<<"stack is now empty."<<endl;
                }
        }

        void displayStack(){
                if(isEmptyStack()){
                        cout<<"stack is empty."<<endl;
                        return;
                }

                cout<<"stack node display: "<<endl;
                for(int i=count-1; i>=0; i--)
                        cout<<arr[i]<<endl;
        }

};
int main(){
        int n;
        cout<<"enter the size of stack: "<<endl;
        cin>>n;
        stack s1(n);

        int ch;
        do{
                cout<<"1. Push into stack. "<<endl;
                cout<<"2. Pop out from stack. "<<endl;
                cout<<"3. display the stack. "<<endl;
                cout<<"4. total node in stack. "<<endl;
                cout<<"5. destroy stack. "<<endl;
                cout<<"enter the option, 0 for exit: ";
                cin>>ch;
                switch(ch){
                        case 1:
                                char ele;
                                cout<<"enter the value for push into stack: ";
                                cin>>ele;
                                s1.pushStack(ele);
                                break;
                        case 2:
                                s1.popStack();
                                break;
                        case 3:
                                s1.displayStack();
                                break;
                        case 4:
                                cout<<"total node in stack: "<<s1.stackCount()<<endl;
                                break;
                        case 5:
                                s1.destroyStack();
                                break;
			case 0:
                                exit(0);
                                break;
                        default:
                                cout<<"invalid input, please put correct input: "<<endl;
                }
        }while(ch!=0);

        return 0;
}