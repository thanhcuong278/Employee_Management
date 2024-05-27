#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

// Enum to define the type of employee
enum class EmployeeType {
    FULL_TIME,
    PART_TIME,
    CONTRACT
};

class Employee {
public:
    int id;
    std::string name;
    EmployeeType type;
    double salary;
    double tax;
    std::string phone_number;
    std::string address;
    std::string dob;
    std::string department_name;
    std::string note;

    Employee();

    // Fill employee information
    void fillEmployee();

    // Print table header
    void printEmployeeHeader() const;

    // Print table footer
    void printEmployeeFooter() const;

    // Print employee details
    void printEmployee() const;

    // Update employee personal information
    void updatePersonalInfo();
};

#endif // EMPLOYEE_H
