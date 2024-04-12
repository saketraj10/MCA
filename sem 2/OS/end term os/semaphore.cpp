#include<iostream>
using namespace std;

int mutex = 1, full = 0, empty = 10, x = 0;

void producer()
{
    --mutex;
    ++full;
    --empty;
    x++;
    cout<<"Producer produces item "<<x<<endl;
    ++mutex;
}

void consumer()
{
    --mutex;
    --full;
    ++empty;
    cout<<"Consumer consumes item "<<x<<endl;
    x--;
    ++mutex;
}

int main()
{
    int n;
    cout<<"Press 1 for producer"<<endl;
    cout<<"Press 2 for consumer"<<endl;
    cout<<"press 3 for exit"<<endl;
    for(int i=1; i>0; i++)
    {
        cout<<"Enter your choice: ";
        cin>>n;
        switch(n)
        {
            case 1:
                if(mutex==1 && empty!=0) producer();
                else cout<<"Buffer is full"<<endl;
                break;
            case 2:
                if(mutex==1 && full!=0) consumer();
                else cout<<"Buffer is empty"<<endl;
                break;
            case 3:
                exit(0);
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}