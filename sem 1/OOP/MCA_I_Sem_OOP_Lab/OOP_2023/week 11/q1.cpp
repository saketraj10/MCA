#include<iostream>
#include<fstream>

using namespace std;

class Employee{
        public:
                char name[20],dept[20],desg[20];
                int id,sal;
                float da,hra,gross,tax,net;

                Employee(){
                        id = sal = 0;
                }

                void getData(){
                        cout << "\nEnter name : ";
                        cin >> name;
                        cout << "Enter department : ";
                        cin >> dept;
                        cout << "Enter designation : ";
                        cin >> desg;
                        cout << "Enter salary : ";
                        cin >> sal;

                        da = sal * 0.12;
                        hra = sal * 0.14;
                        tax = sal * 0.3;
                        gross = sal + da + hra;
                        net = gross - tax;
                }

                void showData(){
                        cout << "\n\nID : " << id;
                        cout << "\nName : " << name;
                        cout << "\nDepartment : " << dept;
                        cout << "\nDesignation : " << desg;
                        cout << "\nSalary : " << sal;
                        cout << "\nDA : " << da;
                        cout << "\nHRA : " << hra;
                        cout << "\nGross sal : " << gross;
                        cout << "\nTax : " << tax;
                        cout << "\nNet sal : " << net;
                }
};


int getEmpId(){
        ifstream file;
        Employee obj;

        file.open("emp_data.dat");
        file.read( (char *) &obj, sizeof(obj) );
        while(!file.eof()){
                file.read( (char *) &obj, sizeof(obj) );
        }
        if(obj.id > 0)
                return obj.id += 1;
        else
                return 1;
}

int main(){
        Employee obj;
        ofstream o_file;
        int n,id,searchId;

        cout << "sizeof(Employee) : " << sizeof(obj)<<endl;

        o_file.open("emp_data.dat",ios::app);
        cout << "Enter number of employees : ";
        cin >> n;

        id = getEmpId();
        while(n!=0){
                obj.getData();
                obj.id = id;
                o_file.write( (char *) &obj, sizeof(obj) );

                id++;
                n--;
        }
        o_file.close();

        cout << "Enter employee id to get pay slip : ";
        cin >> searchId;
        cout << "EMPLOYEE DATA : ";
        ifstream i_file;
        i_file.open("emp_data.dat");
        i_file.read( (char *) &obj, sizeof(obj) );
        while(!i_file.eof()){
                if(searchId == obj.id){
                        obj.showData();
                        break;
                }
                i_file.read( (char *) &obj, sizeof(obj) );
        }
        cout << endl;
        return 0;
}