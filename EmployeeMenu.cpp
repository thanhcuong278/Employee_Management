#include "EmployeeMenu.h"
#include "DesignMain.h"
#include <limits>
#include <iostream>

void EmployeeMenu::display(EmployeeManager& manager) {
    int employeeId;
    std::string password;

    // Prompt user for employee ID
    std::cout << "=== Employee Login ===\n";
    std::cout << "Enter your employee ID: ";

    // Validate input for employee ID
    if (!(std::cin >> employeeId)) {
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        std::cout << "Invalid input. Please enter a number for ID.\n";
        return;
    }

    // Prompt user for password
    std::cout << "Enter your password: ";
    std::cin >> password;

    // Check if employee exists and credentials are correct
    if (manager.employeeExists(employeeId) && manager.employeeLogin(employeeId, password)) {
        int choice;
        do {
                clearScreen();
            // Display employee menu options
                centerAlign("=========Employee Menu=========");
                centerAlign("| 1.View personal information |");
                centerAlign("-------------------------------");
                centerAlign("|2.Update personal information|");
                centerAlign("-------------------------------");
                centerAlign("|           3.Logout          |");
                centerAlign("-------------------------------");
                centerAlign("Enter your choice: ");
                centerAlignChoicePrompt();   

            // Validate input for menu choice
            if (!(std::cin >> choice)) {
                std::cin.clear(); // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                std::cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            // Handle menu options
            switch (choice) {
                case 1:
                    // View personal information
                    manager.searchEmployees(employeeId);
                    break;
                case 2:
                    // Update personal information
                    manager.editEmployee(employeeId);
                    break;
                case 3:
                    // Logout
                    std::cout << "Logging out.\n";
                    return;
                default:
                    // Handle invalid menu choices
                    std::cout << "Invalid choice. Please enter a number from 1 to 3.\n";
                    break;
            }
            system("pause");
        } while (choice != 3); // Loop until user chooses to logout
    } else {
        // Handle invalid login credentials
        std::cout << "Invalid employee ID or password. Access denied.\n";
    }
}
