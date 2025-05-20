#include <iostream>
#include <fstream>
using namespace std;

class intake {
    string username, email, password;
    fstream file;

public:
    void login();
    void signup();
    void forgot();
};

void intake::signup() {
    cout << "---------SIGNUP----------" << endl;
    cout << "\nEnter your user name: ";
    getline(cin, username);
    cout << "\nEnter your email address: ";
    getline(cin, email);
    cout << "\nEnter password: ";
    getline(cin, password);
    file.open("loginData.txt", ios::out | ios::app);
    file << username << "*" << email << "*" << password << endl;
    file.close();
    cout << "Signup successful!\n";
}

void intake::login() {
    cout << "------------LOGIN--------------" << endl;
    string searchname, searchpass;
    cout << "\nEnter your user name: ";
    getline(cin, searchname);
    cout << "\nEnter password: ";
    getline(cin, searchpass);

    bool found = false;
    file.open("loginData.txt", ios::in);
    while (getline(file, username, '*') &&
           getline(file, email, '*') &&
           getline(file, password)) {
        if (username == searchname && password == searchpass) {
            cout << "\nLogin success\n";
            cout << "Email: " << email << endl;
            found = true;
            break;
        }
    }
    file.close();
    if (!found)
        cout << "Invalid username or password.\n";
}

void intake::forgot() {
    cout << "--------PASSWORD RECOVERY--------" << endl;
    string searchname, searchid;
    cout << "\nEnter your user name: ";
    getline(cin, searchname);
    cout << "\nEnter email id: ";
    getline(cin, searchid);

    bool found = false;
    file.open("loginData.txt", ios::in);
    while (getline(file, username, '*') &&
           getline(file, email, '*') &&
           getline(file, password)) {
        if (username == searchname && email == searchid) {
            cout << "Account found.\n";
            cout << "Password: " << password << endl;
            found = true;
            break;
        }
    }
    file.close();
    if (!found)
        cout << "Invalid username or email.\n";
}

int main() {
    intake obj;
    char choice;
    do {
        cout << "\n1. Login\n2. Sign up\n3. Forgot password\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Prevent newline issues

        switch (choice) {
            case '1':
                obj.login();
                break;
            case '2':
                obj.signup();
                break;
            case '3':
                obj.forgot();
                break;
            case '4':
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
//getline() advances the cursor automatically.
//the file's internal cursor (aka the file pointer) automatically moves to the start of the next line on the next loop.


