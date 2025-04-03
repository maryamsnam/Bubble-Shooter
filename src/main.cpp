#include <iostream>   // Basic I/O
#include <cstdlib>    // For system() calls
#include "auth.h"     // Login/registration functions
#include "game.h"     // Game logic functions
int main() {
    // Initialize game state if needed
    bool isRunning = true;
    
    while (isRunning) {
        // Clear screen (platform-specific)
        system("cls");  // Windows
        // system("clear");  // Linux/Mac

        // Display main menu
        std::cout << "***************************\n";
        std::cout << "     BUBBLE SHOOTER\n";
        std::cout << "***************************\n\n";
        std::cout << "1. Login\n";
        std::cout << "2. Register\n";
        std::cout << "3. Forgot Credentials\n";
        std::cout << "4. Exit\n\n";
        std::cout << "Enter choice: ";

        // Handle user input
        int choice;
        std::cin >> choice;

        switch (choice) {
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
                isRunning = false;
                break;
            default:
                std::cout << "Invalid choice! Try again.\n";
                system("pause");  // Wait for user input
        }
    }

// Validate input to prevent crashes
if (!(std::cin >> choice)) {
    std::cin.clear();  // Clear error flags
    std::cin.ignore(10000, '\n');  // Discard bad input
    std::cout << "Numbers only, please!\n";
    continue;
}
// After successful login:
if (authenticated) {
    initGame();  // Defined in game.cpp
    startGameLoop();
}

    std::cout << "Thanks for playing!\n";
    return 0;
}
