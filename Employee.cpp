#include "Employee.h"
#include <iostream>
#include <limits>
#include <regex>
#include <iomanip>
#include "DesignMain.h"

// Default constructor
Employee::Employee() {}

    // Fill employee information from user input
    void Employee::fillEmployee() {
        // Input and validate employee ID
        do {
            system("cls");
            std::cout << "Enter employee ID: ";
            std::cin >> id;
            if (std::cin.fail() || id < 0) {
                std::cin.clear();   // Clear error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                std::cout << "Invalid input. ID must be positive digits. Please try again.\n";
            }
        } while (id < 0);   // Repeat until valid input is received

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore leftover newline

        // Input and validate employee name
        do {
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            if (name.empty())
                std::cout << "Name cannot be empty. Please try again.\n";
        } while (name.empty());

        // Input and validate employee salary
        do {
            std::cout << "Enter salary: ";
            std::cin >> salary;
            if (std::cin.fail() || salary <= 0) {
                std::cin.clear();   // Clear error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                std::cout << "Invalid input. Salary must be digits and greater than 0. Please try again.\n";
            }
        } while (salary <= 0);  // Repeat until valid input is received

        // Input and validate employee phone number
        do {
            std::cout << "Enter phone number: ";
            std::cin >> phone_number;
            if (!std::regex_match(phone_number, std::regex("\\d{10}"))) // Using regular expression to validate phone number format
                std::cout << "Phone number must be 10 digits. Please try again.\n";
        } while (!std::regex_match(phone_number, std::regex("\\d{10}")));   // Repeat until valid input is received

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore leftover newline

        // Input employee address
        std::cout << "Enter address: ";
        std::getline(std::cin, address);

        // Input and validate employee date of birth
        do {
            std::cout << "Enter date of birth (dd/mm/yyyy): ";
            std::getline(std::cin, dob);
            if (!std::regex_match(dob, std::regex("\\d{2}/\\d{2}/\\d{4}"))) // Using regular expression to validate date of birth format
                std::cout << "Invalid date format. Please use dd/mm/yyyy format.\n";
        } while (!std::regex_match(dob, std::regex("\\d{2}/\\d{2}/\\d{4}")));   // Repeat until valid input is received

        // Input and validate employee type
        int type_choice;
        do {
            std::cout << "========================================" << std::endl ;
            std::cout << "Choose employee type:\n";
            std::cout << "1.Full-Time\n"          ;
            std::cout << "2.Part-Time\n"          ;
            std::cout << "3.Contract \n"          ;
            std::cout << "Enter your choice: "    ;
            std::cin >> type_choice ;
            if (std::cin.fail() || type_choice < 1 || type_choice > 3) {
                std::cin.clear();   // Clear error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                std::cout << "Invalid choice. Please enter 1, 2, or 3.\n";
            }
        } while (type_choice < 1 || type_choice > 3);   // Repeat until valid input is received

        // Set employee type and calculate tax based on type
        switch (type_choice) {
            case 1:
                type = EmployeeType::FULL_TIME;
                break;
            case 2:
                type = EmployeeType::PART_TIME;
                break;
            case 3:
                type = EmployeeType::CONTRACT;
                break;
        }

        // Calculate tax based on employee type
        if (type == EmployeeType::FULL_TIME) tax = 0.1 * salary;
        else if (type == EmployeeType::PART_TIME) tax = 0.15 * salary;
        else tax = 0.2 * salary;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear newline character in the input buffer

        // Input employee department name
        std::cout << "========================================" << std::endl;
        std::cout << "Enter department name:\n";
        std::getline(std::cin, department_name);
        std::cout << "\n\n";
    }
    // Print table header for employee details
    void Employee::printEmployeeHeader() const {
        std::cout << "+=====+======================+============+=============+=============+==============+===========================+===================+====================+===========================+\n";
        std::cout << "| ID  | Name                 | Type       | Salary      | Tax         | Phone Number | Address                   | Date of Birth     | Department Name    | Notification              |\n";
        std::cout << "+=====+======================+============+=============+=============+==============+===========================+===================+====================+===========================+\n";
    }

    // Print table footer for employee details
    void Employee::printEmployeeFooter() const {
        std::cout << "+=====+======================+============+=============+=============+==============+===========================+===================+====================+===========================+\n";
    }

    // Print employee details
    void Employee::printEmployee() const {
        // Convert employee type enum to string
        std::string type_str;
        switch (type) {
            case EmployeeType::FULL_TIME:
                type_str = "Full-Time";
                break;
            case EmployeeType::PART_TIME:
                type_str = "Part-Time";
                break;
            case EmployeeType::CONTRACT:
                type_str = "Contract";
                break;
        }

        // Print employee details in a formatted table row
        std::cout << "| " << std::setw(3) << id << " | " << std::setw(20) << std::left << name.substr(0, 19) << " | ";
        std::cout << std::setw(10) << type_str << " | ";
        std::cout << std::fixed << std::setprecision(2) << std::setw(11) << salary << " | ";
        std::cout << std::setw(11) << tax << " | ";
        std::cout << std::setw(12) << phone_number << " | ";
        std::cout << std::setw(25) << address.substr(0, 24) << " | ";
        std::cout << std::setw(18) << dob << " | ";
        std::cout << std::setw(18) << department_name.substr(0, 17) << " | ";
        std::cout << std::setw(25) << note.substr(0, 24) << " |\n";
    }

    // Update employee personal information
    void Employee::updatePersonalInfo() {
        clearScreen();
        centerAlign("Select the information you want to update (Enter 0 to update all):\n");
        centerAlign("0. Update all\n");
        centerAlign("1. Name\n");
        centerAlign("2. Salary\n");
        centerAlign("3. Phone Number\n");
        centerAlign("4. Address\n");
        centerAlign("5. Date of Birth\n");
        centerAlign("6. Employee Type\n");
        centerAlign("7. Department\n");
        centerAlign("Enter your choice: ");
        centerAlignChoicePrompt() ;

        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();   // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid input. Please enter a number.\n";
            return;
        }

        std::string temp; // Temporary variable for input

        // Handle the update based on user choice
        switch (choice) {
                    case 0:
            fillEmployee(); // Update all information
            break;
            system("cls");
        case 1:
            do {
                std::cout << "Enter new name: ";
                std::cin.ignore();  // Ignore leftover newline
                std::getline(std::cin, name);   // Input new name
                if (name.empty())
                    std::cout << "Name cannot be empty. Please try again.\n";
            } while (name.empty());
            break;
            system("cls");
        case 2:
            do {
                std::cout << "Enter new salary: ";
                std::cin >> salary; // Input new salary
                if (std::cin.fail() || salary <= 0) {
                    std::cin.clear();   // Clear error flags
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                    std::cout << "Invalid input. Salary must be digits and greater than 0. Please try again.\n";
                }
            } while (salary <= 0);
            break;
            system("cls");
        case 3:
            do {
                std::cout << "Enter new phone number: ";
                std::cin >> phone_number;   // Input new phone number
                if (!std::regex_match(phone_number, std::regex("\\d{10}"))) // Using regular expression to validate phone number format
                    std::cout << "Phone number must be 10 digits. Please try again.\n";
            } while (!std::regex_match(phone_number, std::regex("\\d{10}")));
            break;
             system("cls");
        case 4:
            do {
                std::cout << "Enter new address: ";
                std::cin.ignore();  // Ignore leftover newline
                std::getline(std::cin, address);    // Input new address
                if (address.empty())
                    std::cout << "Address cannot be empty. Please try again.\n";
            } while (address.empty());
            break;
             system("cls");
        case 5:
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore leftover newline
            do {
                std::cout << "Enter new date of birth (dd/mm/yyyy): ";
                std::getline(std::cin, dob);    // Input new date of birth
                if (!std::regex_match(dob, std::regex("\\d{2}/\\d{2}/\\d{4}"))) // Using regular expression to validate date of birth format
                    std::cout << "Invalid date format. Please use dd/mm/yyyy format.\n";
            } while (!std::regex_match(dob, std::regex("\\d{2}/\\d{2}/\\d{4}")));   // Repeat until valid input is received
            break;
             system("cls");
        case 6:
            int type_choice;
            do {
                std::cout << "Enter new employee type (1 for Full-Time, 2 for Part-Time, 3 for Contract): ";
                std::cin >> type_choice;
                if (std::cin.fail() || type_choice < 1 || type_choice > 3) {
                    std::cin.clear();   // Clear error flags
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                    std::cout << "Invalid input. Please enter 1, 2, or 3.\n";
                }
            } while (type_choice < 1 || type_choice > 3);
            switch (type_choice) {
                case 1:
                    type = EmployeeType::FULL_TIME;
                    break;
                case 2:
                    type = EmployeeType::PART_TIME;
                    break;
                case 3:
                    type = EmployeeType::CONTRACT;
                    break;
                default:
                    std::cout << "Invalid choice.\n";
            }
            break;
             system("cls");
        case 7:
            do {
                std::cout << "Enter new department: ";
                std::cin.ignore();  // Ignore leftover newline
                std::getline(std::cin, department_name);    // Input new department
                if (department_name.empty())
                    std::cout << "Department name cannot be empty. Please try again.\n";
            } while (department_name.empty());
            break;
             system("cls");
        default:
            std::cout << "Invalid choice.\n";   // Handle invalid choice
    }
}
