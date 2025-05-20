#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

class Airlines {
private:
    string flight, destination, departure;
    int seats;

public:
    Airlines(string fl, string des, string dep, int st) {
        flight = fl;
        destination = des;
        departure = dep;
        seats = st;
    }

    string getflight() { return flight; }
    string getdes() { return destination; }
    string getdep() { return departure; }
    int getseat() { return seats; }

    void update() {
        if (seats > 0) {
            seats--;
        }
    }

    void writeToFile(ofstream& file) {
        file << flight << "*" << destination << "*" << departure << "*" << seats << "\n";
    }
};

void display() {
    ifstream file("flightdetails.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    Airlines flight1("f101", "India", "UAE", 20);
    Airlines flight2("f102", "India", "USA", 2);
    Airlines flight3("f103", "India", "CANADA", 10);

    ofstream file("flightdetails.txt", ios::out);
    flight1.writeToFile(file);
    flight2.writeToFile(file);
    flight3.writeToFile(file);
    file.close();

    char choice;
    do {
        cout << "1. Reserve a seat\n2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            display();
            char f;
            cout << "Choose flight (a: f101, b: f102, c: f103): ";
            cin >> f;

            switch (f) {
            case 'a':
                if (flight1.getseat() > 0) {
                    flight1.update();
                    cout << "Seat reserved\n";
                } else {
                    cout << "Seat not available\n";
                }
                break;
            case 'b':
                if (flight2.getseat() > 0) {
                    flight2.update();
                    cout << "Seat reserved\n";
                } else {
                    cout << "Seat not available\n";
                }
                break;
            case 'c':
                if (flight3.getseat() > 0) {
                    flight3.update();
                    cout << "Seat reserved\n";
                } else {
                    cout << "Seat not available\n";
                }
                break;
            default:
                cout << "Invalid flight selection!\n";
            }

            ofstream file("flightdetails.txt", ios::out);
            flight1.writeToFile(file);
            flight2.writeToFile(file);
            flight3.writeToFile(file);
            file.close();
            break;
        }
        case '2':
            cout << "Exiting....\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != '2');

    return 0;
}
