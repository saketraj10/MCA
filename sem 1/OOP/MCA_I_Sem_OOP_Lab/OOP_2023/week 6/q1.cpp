#include<iostream>
using namespace std;

class my_string
{
        char str[20];

        public:
        void getstring()
        {
                cin>>str;

        }
        void display()
        {
                cout<<str<<endl;
        }

        int operator <= (my_string );
};

int my_string :: operator <= (my_string c)
{
        int i=0;
        while(str[i] !='\0' || c.str[i] !='\0')
        {
                if(str[i] == c.str[i])
                {
                        i++;

                }
                else
                        return str[i]-c.str[i];

        }
}

int main()
{
        my_string s1,s2;
        int n;

        cout<<"Enter first string: "<<endl;
        s1.getstring();
        cout<<"Enter second string: "<<endl;
        s2.getstring();
        cout<<"string 1: "; s1.display();
        cout<<"string 2: "; s2.display();
        n = s1<=s2;

        if(n == 0)
                cout<<"strings are equal"<<endl;

        else if(n > 0)
                cout<<"string 1 is greater than string 2"<<endl;
        else if(n < 0)
                cout<<"string 1 is smaller than string 2"<<endl;
        return 0;
}