//Program to determine if the given string is a palindrome or not
//Name: Saket Raj
//Reg No: 230970079
//Date: 31-08-2023
#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;

void palindrome(char str[20],int l)
{
        char str_rev[10];
        int j=0;
        for(int i=l-1;i>=0;i--)
        {
                str_rev[j]=str[i];
                j++;
        }
        str_rev[j]='\0';
        cout<<"String reverse:"<<str_rev<<endl;
        if(strcmp(str_rev,str)==0)
        {
                cout<<"String is palindrome"<<endl;
        }
        else
        {
                cout<<"string is not palindrome"<<endl;

	}
}
int main()
{
        char str[20];
        int length;
        system("clear");
        cout<<"enter the string"<<endl;
        cin>>str;
        length=strlen(str);
        palindrome(str,length);
        return 0;
}