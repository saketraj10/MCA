#include<iostream>
#include<fstream>
using namespace std;
int main(){
        ofstream o_obj;
        ifstream i_obj;
        int no_char,no_letter,no_digit,no_line,no_space;
        no_char = no_letter = no_digit  = no_space = 0;
        no_line=1;
        string content;
        cout << "\nEnter the content( '#' to end) : "<<endl;
        getline(cin,content,'#');
        o_obj.open("content.txt");
        o_obj << content;
        o_obj.close();
        cout << "***File created\n";
        char ch;
        i_obj.open("content.txt");
        while(1){
                i_obj.get(ch);
                if(i_obj.eof())
                        break;
                no_char += 1;
                if(int(ch)>=65 && int(ch)<=90 || int(ch)>=97 && int(ch)<=122)
                        no_letter+=1;
                if(int(ch)>=48&&int(ch)<=57)
                        no_digit+=1;
                if(ch=='\n')

                        no_line+=1;
                if(ch==' ')
                        no_space+=1;
        }
        cout << "No. of chars : " << no_char << endl;
        cout << "No. of letter : " << no_letter << endl;
        cout << "No. of digit : " << no_digit << endl;
        cout << "No. of line : " << no_line << endl;
        cout << "No. of spaces : " << no_space << endl;
        return 0;
}