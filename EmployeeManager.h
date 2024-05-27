#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include "Employee.h"
#include <vector>

class EmployeeManager {
public:
    std::vector<Employee> employees;

    // Add a new employee
    void addEmployee();

    // Edit existing employee by ID
    void editEmployee(int id);

    // Remove employee by ID
    void removeEmployee(int id);

    // Print all employees
    void printEmployees() const;

    // Search for employees by ID
    void searchEmployees(int id) const;

    // Sort employees by department
    void sortEmployeesByDepartment();

    // Check if employee exists by ID
    bool employeeExists(int id) const;

    // Manager login function
    bool managerLogin(const std::string& username, const std::string& password) const;

    // Employee login function
    bool employeeLogin(int id, const std::string& password) const;

    // Save employees data to CSV file
    void saveDataToCSV(const std::string& filename) const;

    // Load employees data from CSV file
    void loadDataFromCSV(const std::string& filename);
};

#endif // EMPLOYEEMANAGER_H
