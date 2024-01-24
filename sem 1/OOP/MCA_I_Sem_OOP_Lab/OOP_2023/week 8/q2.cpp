#include<iostream>
using namespace std;
class employee{
    int code;
    char name[30];
    public:
    void putdata(){
        cout<<"Enter details of employee: "<<endl;
        cout<<"Code: ";
        cin>>code;
        cout<<"Name: ";
        cin>>name;
    }
    void display(){
        cout<<"Employee details: "<<endl;
        cout<<"Code: "<<code<<endl;
        cout<<"Name: "<<name<<endl;
    }
};
class account: virtual public employee{
    public:
    float pay;
    void put_account(){
        cout<<"Pay: ";
        cin>>pay;
    }
    void display_account(){
        cout<<"Pay: "<<pay<<endl;
    }
};
class admin: virtual public employee{
    public:
    float exp;
    void put_admin(){
        cout<<"Experience: ";
        cin>>exp;
    }
    void display_admin(){
        cout<<"Experience: "<<exp<<endl;
    }
};
class master: public account, public admin{
    public:
    void put_master(){
        putdata();
        put_account();
        put_admin();
    }
    void display_master(){
        display();
        display_account();
        display_admin();
    }
    void update_master(){
        display_master();
        cout<<"Enter the details to update: "<<endl;
        cout<<"Pay: ";
        cin>>pay;
        cout<<"Experience: ";
        cin>>exp;
        cout<<"Updated successfully."<<endl;
    }
};
int main(){
    master m;
    int ch;
    do{
        cout<<"Menu: "<<endl;
        cout<<"1. Create"<<endl;
        cout<<"2. Update"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                m.put_master();
                break;
            case 2:
                m.update_master();
                break;
            case 3:
                m.display_master();
                break;
            case 4:
                cout<<"Terminated."<<endl;
                exit(0);
            default:
                cout<<"Invalid choice"<<endl;
                exit(0);
        }
    }
    while(ch != 0);
    return 0;
}