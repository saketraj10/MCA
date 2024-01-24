#include<iostream>
#include<fstream>

using namespace std;

class Item{
        public:
                char item_name[20];
                int item_code,unit_price,quantity;

                Item(){
                        item_code=0;
                }

                void getData(){
                        cout << "Enter Item name : ";
                        cin >> item_name;
                        cout << "Enter Unit price : ";
                        cin >> unit_price;
                        cout << "Enter quantity in hand : ";
                        cin >> quantity;
                }
                void showData(){
                        cout << "\n\nItem code : " << item_code << "\tItem name : " << item_name;
                        cout << "\nUnit price : " << unit_price << "\tQuantity : " << quantity << endl;
                }
};

int getItemId(){
        ifstream file;
        file.open("item_data.dat");
        Item obj;
        file.read( (char *) &obj,sizeof(obj) );
        while(!file.eof()){
                file.read( (char *) &obj,sizeof(obj) );
        }
        if(obj.item_code > 0)
                return obj.item_code += 1;
        else
                return 1;
}

int main(){
        ofstream o_file;
        fstream i_file;
        Item obj;
        int ch,id,i_num,pos,found;

        do{
                cout << "\n\n1.Add item\n2.Modify item\n3.Display Item\n4.Exit\nEnter your choice : ";
                cin >> ch;
                switch(ch){
                        case 1:
                                o_file.open("item_data.dat",ios::app);
                                id = getItemId();
                                obj.getData();
                                obj.item_code = id;
                                o_file.write( (char *) &obj, sizeof(obj) );
                                o_file.close();
                                cout << "\nItem added";
                                break;
                        case 2:
                                pos=0;
                                found=0;
                                cout << "Enter Item code : ";
                                cin >> i_num;
                                i_file.open("item_data.dat");
                                i_file.read( (char *) &obj, sizeof(obj) );
                                while(!i_file.eof()){
                                        if(i_num == obj.item_code){
                                                found = 1;
                                                cout << "\nEnter new item name,unit price and quantity in hand : ";
                                                cin >> obj.item_name >> obj.unit_price >> obj.quantity;
                                                i_file.seekp(pos);
                                                i_file.write( (char *) &obj, sizeof(obj));
                                                break;
                                        }
                                        pos += sizeof(obj);
                                        i_file.read( (char *) &obj, sizeof(obj) );
                                }
                                if(found == 0)
                                        cout << "\nItem not found";
                                i_file.close();
                                break;
                        case 3:
                                found = 0;
                                cout << "Enter Item code : ";
                                cin >> i_num;
                                i_file.open("item_data.dat");
                                i_file.read( (char *) &obj,sizeof(obj));
                                while(!i_file.eof()){
                                        if(i_num == obj.item_code){
                                                found = 1;
                                                obj.showData();
                                                break;
                                        }
                                        i_file.read( (char *) &obj,sizeof(obj));
                                }
                                if(found == 0)
                                        cout << "\nItem not found";
                                i_file.close();
                                break;
                        default: cout << endl;
                }
        }while(ch!=4);

        return 0;
}