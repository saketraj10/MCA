#include<iostream>
using namespace std;
class cricketPlayer
{
        char player_code[6];
        int no_of_matches,not_outs;
        public:
        int total_runs;
        char name[25];

        cricketPlayer()
        {
                no_of_matches = 0;
                not_outs = 0;
                total_runs= 0;
        }
        void getData()
        {
                cout<<"Enter Player Details."<<endl;
                cout<<"___________________________________"<<endl;
                cout<<"Code: "<<endl;
                cin>>player_code;
                cout<<"Name: "<<endl;
                cin>>name;
		        cout<<"Number of matches played: "<<endl;
                cin>>no_of_matches;
                cout<<"Total runs scored: "<<endl;
                cin>>total_runs;
                cout<<"Number of times not out: "<<endl;
                cin>>not_outs;
                if(no_of_matches<not_outs)
                {
                        cout<<"number of matches should be more then not outs"<<endl;
                        exit(0);
                }
        }

        void display()
        {
                cout<<player_code<<"\t"<<name<<"\t"<<no_of_matches<<"\t"<<total_runs<<"\t"<<not_outs<<endl;
        }

        float avgRuns()
        {

                return total_runs/float(no_of_matches-not_outs);
        }
};

int main(){
        cricketPlayer obj[10];
        int n,choice,p_no;
        float total_avg=0,a=0;

        cout<<"enter number of players : "<<endl;
        cin>>n;
        if(n<=10)
        {
                cricketPlayer obj[n],temp;
        do{
                cout<<"MENU"<<endl;
                cout<<"____________________________________________________________"<<endl;
                cout<<"1.Enter player details."<<endl;
                cout<<"2.Display average runs of a single player."<<endl;
                cout<<"3.Display average runs all players."<<endl;
                cout<<"4.Display list of players in sorted order as per total runs."<<endl;
                cout<<"\nEnter your choice: ";
                cin>>choice;
                cout<<"____________________________________________________________"<<endl;
switch(choice){
        case 1:
                cout<<"\n\tenter number of players : ";
                cin>>n;
                for(int i=0;i<n;i++)
                {
                        cout<<"Player "<<i+1<<endl;
                        obj[i].getData();
                }
                break;
        case 2:
                cout<<"\n\nEnter a player number to get his average runs: ";
                cin>>p_no;
                obj[p_no-1].display();
                cout<<"-------------------------------"<<endl;
                cout<<"\tAverage runs of "<<obj[p_no-1].name<<" is : "<<obj[p_no-1].avgRuns()<<endl;
                break;
        case 3:
                cout<<"\n\n\tAverage runs of all players: ";
                cout<<"Player\tName\tAverage Runs"<<endl;
                for(int i=0;i<n;i++)
                {
                        cout<<i+1<<"\t"<<obj[i].name<<"\t"<<obj[i].avgRuns()<<endl;
                        total_avg=total_avg + obj[i].avgRuns();

                }
                a=total_avg/n;
                cout<<a;
                cout<<"avg runs of all players : "<<avgRuns(total_avg,n);
                break;
        case 4:
                cout<<"List of players in sorted order as per total runs : "<<endl;
                cricketPlayer temp;
                for(int i=0;i<n;i++)
                {
                        for(int j=1;j<n;j++)
                        {
                                if(obj[i].total_runs<obj[j].total_runs)
                                {
                                        temp = obj[i];
                                        obj[i] = obj[j];
                                        obj[j] = temp;
                                 }
                        }
                }
                cout<<"____________________________________________________________"<<endl;
                cout<<"\t\tPlayer Details"<<endl;
                cout<<"____________________________________________________________"<<endl;
                cout<<"Code\tName\tMatches Played\tTotal Runs\tNot Outs"<<endl;
                for(int i=0;i<n;i++)
                {
                        obj[i].display();
                        cout<<endl;
                }
                break;
        default:
                cout<<"invalid choice."<<endl;
                exit(0);
}
        }
        while(choice !=0);
        }
        else
        {
                cout<<"No of players should be less than 10"<<endl;
                exit(0);
        }
        return 0;
}