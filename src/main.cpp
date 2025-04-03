#include <iostream>
#include "auth.h"
#include "game.h"

int main() {
    int choice;
    while(true) {
        system("cls");
        std::cout << "*********\n\n";
        std::cout << "       Welcome to Bubble Shooter\n\n";
        std::cout << "1. LOGIN\n";
        std::cout << "2. REGISTER\n";
        std::cout << "3. FORGOT PASSWORD\n";
        std::cout << "4. Exit\n";
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: login(); break;
            case 2: registr(); break;
            case 3: forgot(); break;
            case 4: return 0;
            default: 
                std::cout << "Invalid choice! Try again\n";
                system("pause");
        }
    }
    return 0;
}
