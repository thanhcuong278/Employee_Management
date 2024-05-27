#ifndef MANAGERMENU_H
#define MANAGERMENU_H

#include "EmployeeManager.h"

class ManagerMenu {
public:
    // Display the manager menu
    void display(EmployeeManager& manager);

    // Create notification for employee
    void createNotification(EmployeeManager& manager);

    // Save employees data to CSV file
    void saveDataToCSV(EmployeeManager& manager);

    // Load employees data from CSV file
    void loadDataFromCSV(EmployeeManager& manager);
};

#endif // MANAGERMENU_H
