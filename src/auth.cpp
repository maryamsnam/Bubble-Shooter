#include "auth.h"
#include <iostream>
#include <cstdlib> // for system()
#include <conio.h> // for getch()

using namespace std;

struct User {
    string username;
    string password;
};

void login() {
    int count = 0;
    string user, pass, u, p;
    system("cls");
    cout << "Please enter your credentials" << endl;
    cout << "USERNAME: ";
    cin >> user;
    cout << "PASSWORD: ";
    cin >> pass;

    ifstream input("database.txt");
    while (input >> u >> p) {
        if (u == user && p == pass) {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count == 1) {
        cout << "\nHello " << user << "\nLogin Successful!\n";
        cout << "Press any key to continue...";
        getch();
    } else {
        cout << "\nLogin Error\nPlease check your username and password\n";
        cout << "Press any key to try again...";
        getch();
        login();
    }
}

void registr() {
    User newUser;
    system("cls");
    cout << "Enter your new username: ";
    cin >> newUser.username;
    cout << "Enter your new password: ";
    cin >> newUser.password;

    ofstream reg("database.txt", ios::app);
    reg << newUser.username << ' ' << newUser.password << endl;
    reg.close();

    system("cls");
    cout << "\nRegistration Successful!\n";
    cout << "Press any key to continue...";
    getch();
}

void forgot() {
    int option;
    system("cls");
    cout << "Forgot your credentials? Don't worry!\n";
    cout << "1. Search your password by username\n";
    cout << "2. Search your username by password\n";
    cout << "3. Return to main menu\n";
    cout << "Enter your choice: ";
    cin >> option;

    switch(option) {
        case 1: {
            int count = 0;
            string searchUser, su, sp;
            cout << "\nEnter your username: ";
            cin >> searchUser;

            ifstream searchU("database.txt");
            while (searchU >> su >> sp) {
                if (su == searchUser) {
                    count = 1;
                    break;
                }
            }
            searchU.close();

            if(count == 1) {
                cout << "\nAccount found!\n";
                cout << "Your password is: " << sp << endl;
            } else {
                cout << "\nUsername not found!\n";
            }
            cout << "Press any key to continue...";
            getch();
            forgot();
            break;
        }
        case 2: {
            int count = 0;
            string searchPass, su2, sp2;
            cout << "\nEnter your password: ";
            cin >> searchPass;

            ifstream searchP("database.txt");
            while (searchP >> su2 >> sp2) {
                if (sp2 == searchPass) {
                    count = 1;
                    break;
                }
            }
            searchP.close();

            if(count == 1) {
                cout << "\nAccount found!\n";
                cout << "Your username is: " << su2 << endl;
            } else {
                cout << "\nPassword not found!\n";
            }
            cout << "Press any key to continue...";
            getch();
            forgot();
            break;
        }
        case 3:
            return;
        default:
            cout << "Invalid choice! Try again...";
            getch();
            forgot();
    }
}
