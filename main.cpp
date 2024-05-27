#include "EmployeeManager.h"
#include "ManagerMenu.h"
#include "EmployeeMenu.h"
#include "Employee.h"
#include "DesignMain.h"
#include <iostream>
#include <limits>


int main() {
    // Initialize the employee manager, manager menu, and employee menu
    EmployeeManager manager;
    ManagerMenu managerMenu;
    EmployeeMenu employeeMenu;
    void setConsoleColor(WORD attributes);
    void setfullscreen();
    setConsoleColor(BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    int role;
    // Main loop to display the menu and handle user input
    do {
        clearScreen();
        centerAlign("====== Main Menu =======");
        centerAlign("|| 1.Login as Manager ||");
        centerAlign("========================");
        centerAlign("||2.Login as Employee ||");
        centerAlign("========================");
        centerAlign("||      3.Exit        ||");
        centerAlign("========================");
        centerAlign("    Enter your role:    ");   centerAlignChoicePrompt();

        // Check if the user input is valid
        if (!(std::cin >> role)) {
            // Clear the error flag and ignore invalid input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        // Handle user input based on their role selection
        switch (role) {
            case 1:
                clearScreen();
                // Display manager menu
                managerMenu.display(manager);
                break;
            case 2:
                clearScreen();
                // Display employee menu
                employeeMenu.display(manager);
                break;
            case 3:
                clearScreen();
                // Exit the program
                std::cout << "Exiting program.\n";
                break;
                system("Pause");
            default:
                // Handle invalid role input
                std::cout << "Invalid role. Please enter 1, 2, or 3.\n";
        }
    } while (role != 3);  // Continue looping until user chooses to exit

    return 0;
}
