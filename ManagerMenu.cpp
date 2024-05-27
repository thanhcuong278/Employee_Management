#include "ManagerMenu.h"
#include <iostream>
#include <limits>
#include "DesignMain.h"

// Function to display the manager menu and handle manager actions
void ManagerMenu::display(EmployeeManager& manager) {
    std::string username;
    std::string password;

    // Manager login section
    centerAlign(  "=== Manager Login ===\n");
    centerAlign(  "Enter username: ");
    centerAlignChoicePrompt();
    std::cin >> username;
    centerAlign(  "Enter password: ");
    centerAlignChoicePrompt();
    std::cin >> password;
    system("cls");

    // Check manager credentials
    if (manager.managerLogin(username, password)) {

        int choice;
        do {
            // Display manager menu options
            centerAlign( "=== Manager Menu === ");
            centerAlign( "1. Add employee\n"        );
            centerAlign( "2. Edit employee\n"       );
            centerAlign( "3. Remove employee\n"     );
            centerAlign( "4. Print employees\n"     );
            centerAlign( "5. Search employee by ID\n");
            centerAlign( "6. Sort employees by department\n");
            centerAlign( "7. Create Notification for Employee\n");
            centerAlign( "8. Save Data to CSV\n");
            centerAlign( "9. Load Data from CSV\n");
            centerAlign( "10. Logout\n");
            centerAlign( "Enter your choice: ");

            // Handle invalid input for menu choice
            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            // Perform actions based on the user's choice
            switch (choice) {
                case 1:
                    clearScreen();
                    manager.addEmployee();
                    break;
                case 2:
                    // Handle editing an employee
                    clearScreen();
                    int id;
                    std::cout << "Enter employee ID to edit: ";
                    if (!(std::cin >> id)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input. Please enter a non-negative integer for ID.\n";
                        continue;
                    }
                    manager.editEmployee(id);
                    break;
                case 3:
                    clearScreen();
                    // Handle removing an employee
                    std::cout << "Enter employee ID to remove: ";
                    if (!(std::cin >> id)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input. Please enter a non-negative integer for ID.\n";
                        continue;
                    }
                    manager.removeEmployee(id);
                    break;
                case 4:
                    clearScreen();
                    // Print all employees
                    manager.printEmployees();
                    break;
                    system("cls");
                case 5:
                    clearScreen();
                    // Search for an employee by ID
                    std::cout << "Enter employee ID to search: ";
                    if (!(std::cin >> id)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input. Please enter a non-negative integer for ID.\n";
                        continue;
                    }
                    manager.searchEmployees(id);
                    break;
                case 6:
                    clearScreen();
                    // Sort employees by department
                    manager.sortEmployeesByDepartment();
                    std::cout << "Employees sorted by department.\n";
                    break;
                case 7:
                    clearScreen();
                    // Create a notification for an employee
                    createNotification(manager);
                    break;
                case 8:
                    clearScreen();
                    // Save data to a CSV file
                    saveDataToCSV(manager);
                    break;
                case 9:
                    system("cls");
                    // Load data from a CSV file
                    loadDataFromCSV(manager);
                    break;
                case 10:
                    system("cls");
                    // Logout
                    std::cout << "Logging out.\n";
                    return;
                default:
                    std::cout << "Invalid choice. Please enter a number from 1 to 10.\n";
            }
        } while (choice != 10);
    } else {
        // Handle invalid login credentials
        std::cout << "Invalid username or password. Access denied.\n";
    }
}

// Function to create a notification for an employee
void ManagerMenu::createNotification(EmployeeManager& manager) {
    int id;
    std::string note;

    // Input employee ID and notification content
    std::cout << "Enter employee ID to create notification: ";
    if (!(std::cin >> id)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a non-negative integer for ID.\n";
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter notification for employee: ";
    std::getline(std::cin, note);

    // Find employee by ID and create notification
    for (auto& e : manager.employees) {
        if (e.id == id) {
            e.note = note;
            std::cout << "Notification created for employee with ID " << id << ".\n";
            return;
        }
    }
    std::cout << "Employee with ID " << id << " not found.\n";
}

// Function to save data to a CSV file
void ManagerMenu::saveDataToCSV(EmployeeManager& manager) {
    std::string filename;

    // Input filename
    std::cout << "Enter filename to save data (e.g., employees.csv): ";
    std::cin >> filename;

    // Call manager method to save data
    manager.saveDataToCSV(filename);
}

// Function to load data from a CSV file
void ManagerMenu::loadDataFromCSV(EmployeeManager& manager) {
    std::string filename;

    // Input filename
    std::cout << "Enter filename to load data from (e.g., employees.csv): ";
    std::cin >> filename;

    // Call manager method to load data
    manager.loadDataFromCSV(filename);
}
