#include<iostream>
using namespace std;
int main()
{
        int i,num,c;
        system("clear");
        cout<<"Enter a number: "<<endl;
        cin>>num;
        for(i=1;i<=num;i++)
        {
                if (i*i*i==num)
                {
                        c=1;
                        break;
                }
                else
                        c=0;
        }
        if(c==1)
        {
                cout<<num<<" is a perfect cube\nCube root is: "<<i<<endl;
        }
        else
        {
                cout<<num<<" is not a perfect cube "<<endl;
        }
        return 0;
}