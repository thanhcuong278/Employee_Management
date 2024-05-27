#include "EmployeeManager.h"
#include "DesignMain.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

// Function to add a new employee to the list
void EmployeeManager::addEmployee() {
    Employee e;
    e.fillEmployee();  // Fill the employee details
    employees.push_back(e);  // Add the employee to the list
    system("cls");
}

// Function to edit an existing employee's details by ID
void EmployeeManager::editEmployee(int id) {
    for (auto &e : employees) {
        if (e.id == id) {
            std::cout << "Enter new information:\n";
            e.updatePersonalInfo();  // Update the personal info of the employee
            return;
        }
    }
    std::cout << "Employee with ID " << id << " not found.\n";
}

// Function to remove an employee from the list by ID
void EmployeeManager::removeEmployee(int id) {
    employees.erase(std::remove_if(employees.begin(), employees.end(), [id](const Employee &e) { return e.id == id; }), employees.end());
}

// Function to print all employees' details
void EmployeeManager::printEmployees() const {
    if (employees.empty()) {
        std::cout << "No employees to print.\n";
        return;
    }

    Employee emp;
    emp.printEmployeeHeader();  // Print the header for the employee list
    for (const auto &e : employees)
        e.printEmployee();  // Print each employee's details
    emp.printEmployeeFooter();  // Print the footer for the employee list
}

// Function to search and print an employee's details by ID
void EmployeeManager::searchEmployees(int id) const {
    bool found = false;
    Employee emp;
    emp.printEmployeeHeader();  // Print the header for the employee search
    for (const auto &e : employees) {
        if (e.id == id) {
            e.printEmployee();  // Print the employee's details
            found = true;
            break;
        }
    }
    if (!found)
        std::cout << "Employee with ID " << id << " not found.\n";
    emp.printEmployeeFooter();  // Print the footer for the employee search
}

// Function to sort employees by their department name
void EmployeeManager::sortEmployeesByDepartment() {
    std::sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b) {
        return a.department_name < b.department_name;
    });
}

// Function to check if an employee exists by ID
bool EmployeeManager::employeeExists(int id) const {
    return std::any_of(employees.begin(), employees.end(), [id](const Employee& e) {
        return e.id == id;
    });
}

// Function to handle manager login with fixed credentials
bool EmployeeManager::managerLogin(const std::string& username, const std::string& password) const {
    return (username == "admin" && password == "123");  // Simplified login check
}

// Function to handle employee login with fixed password
bool EmployeeManager::employeeLogin(int id, const std::string& password) const {
    return password == "1";  // Simplified password check
}

// Function to save employee data to a CSV file
void EmployeeManager::saveDataToCSV(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << " for writing.\n";
        return;
    }

    file << "ID,Name,Type,Salary,Tax,Phone Number,Address,Date of Birth,Department Name,Notification\n";
    for (const auto& e : employees) {
        std::string type_str;
        switch (e.type) {
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

        file << e.id << "," << e.name << "," << type_str << "," << e.salary << "," << e.tax << ",";
        file << e.phone_number << "," << e.address << "," << e.dob << "," << e.department_name << "," << e.note << "\n";
    }

    std::cout << "Data saved to " << filename << " successfully.\n";
    file.close();
}

// Function to load employee data from a CSV file
void EmployeeManager::loadDataFromCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << " for reading.\n";
        return;
    }

    employees.clear();  // Clear old data before loading new data

    std::string line;
    std::getline(file, line);  // Skip the header line
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;

        Employee e;

        std::getline(iss, token, ',');
        e.id = std::stoi(token);

        std::getline(iss, e.name, ',');
        std::getline(iss, token, ',');
        if (token == "Full-Time")
            e.type = EmployeeType::FULL_TIME;
        else if (token == "Part-Time")
            e.type = EmployeeType::PART_TIME;
        else if (token == "Contract")
            e.type = EmployeeType::CONTRACT;
        else {
            std::cerr << "Error: Invalid employee type in CSV.\n";
            return;
        }
        std::getline(iss, token, ',');
        e.salary = std::stod(token);
        std::getline(iss, token, ',');
        e.tax = std::stod(token);
        std::getline(iss, e.phone_number, ',');
        std::getline(iss, e.address, ',');
        std::getline(iss, e.dob, ',');
        std::getline(iss, e.department_name, ',');
        std::getline(iss, e.note, ',');

        employees.push_back(e);  // Add the loaded employee to the list
    }

    std::cout << "Data loaded from " << filename << " successfully.\n";
    file.close();
}
