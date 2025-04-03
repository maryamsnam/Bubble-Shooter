#include "auth.h"
#include <iostream>
#include <cstdlib> // for system()

using namespace std;

void displayMenu() {
    system("cls");
    cout << "************************************\n";
    cout << "*      BUBBLE SHOOTER GAME         *\n";
    cout << "************************************\n\n";
    cout << "1. LOGIN\n";
    cout << "2. REGISTER\n";
    cout << "3. FORGOT PASSWORD/USERNAME\n";
    cout << "4. EXIT\n\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    
    while(true) {
        displayMenu();
        cin >> choice;

        switch(choice) {
            case 1:
                login();
                break;
            case 2:
                registr();
                break;
            case 3:
                forgot();
                break;
            case 4:
                cout << "Thank you for playing!\n";
                exit(0);
            default:
                cout << "Invalid choice! Please try again...\n";
                system("pause");
        }
    }

    return 0;
}
