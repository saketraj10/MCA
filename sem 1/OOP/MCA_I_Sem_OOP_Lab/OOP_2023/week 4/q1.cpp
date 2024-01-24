#include<iostream>
using namespace std;

class flight {
    int flight_no;
    char dest[25];
    float fuel, distance;

    float calculate_fuel() {
        if (distance > 2000) {
            fuel = 2200;
            return fuel ;
        }
        else if (distance > 1000) {
            fuel = 1100;
            return fuel ;
        }
        else {
            fuel = 500;
            return fuel ;
        }
    }

public:
    flight() {
        distance = 500;
    }

    void information_entry() {
        cout << "Flight Number : "<<endl;
        cin >> flight_no;
        cout << "Destination : "<<endl;
        cin >> dest;
        cout << "Distance : "<<endl;
        cin >> distance;
    }

    void display_info() {
        cout << "Flight Number : " << flight_no << endl;
        cout << "Destination : " << dest << endl;
        cout << "Distance : " << distance << " km." << endl;
        fuel = calculate_fuel();
        cout << "Total fuel: " << fuel << endl;
    }
};

int main() {
    flight f1;
    f1.information_entry();
    f1.display_info();
    return 0;
}
