# Employee Management System

## Overview:
The Employee Management System is a C++ application designed to manage employee data within a company. It allows managers to add, edit, remove, search, and print employee information. Employees can also view and update their personal information.

>launch the file.exe directly to use the App.
>Manager have full access to manipulate the data.
>Employee account can only view and update their personal information.

## Features:
### Manager Functions
Login: Secure login for managers.

Add Employee: Add a new employee to the system.

Edit Employee: Update employee details.

Remove Employee: Delete an employee from the system.

Print Employees: Display all employees.

Search Employee by ID: Find an employee using their ID.

Sort Employees by Department: Organize employees by their department.

Create Notification for Employee: Send notifications to employees.

Save Data to CSV: Export employee data to a CSV file.

Load Data from CSV: Import employee data from a CSV file.

### Employee Functions
Login: Secure login for employees.

View Personal Information: View individual employee details.

Update Personal Information: Update their own details.

## Usage
- Install a C++ compiler (e.g., GCC).
- Write your C++ code and save it with the .cpp extension.
- Open the terminal (Linux/Mac) or Command Prompt (Windows).
- Navigate to the directory containing your C++ source code.
- Compile the code using the command: `g++ -o output_filename source_file.cpp`.
- Run the executable using: `./output_filename` (Linux/Mac) or `output_filename.exe` (Windows).
- Test and verify your program's functionality.
Upon running the program, you will be presented with the main menu:

=== Main Menu ===
1. Login as Manager
2. Login as Employee
3. Exit
Enter your role:

Choose the appropriate role and follow the prompts for login and subsequent actions.
>for testing purpose password for Manager are set to "123".
### Manager Login
Username: admin
Password: 123

>for testing purpose passwords for Employee are set to "1".
### Employee Login
Username: ID (Note: The ID number is a number given to employees by Manager, meaning it must exist to log in)
Password: 1 (All employees use this password for simplicity)

At Manager Menu
After successful login, managers can choose from various options to manage employees.

At Employee Menu
After successful login, employees can view and update their personal information.

### CSV File Format
When saving to or loading from a CSV file, the following format is used:
ID,Name,Type,Salary,Tax,Phone Number,Address,Date of Birth,Department Name,Notification
Example:
1,Cuong,Full-Time,50000,5000,1234567890,HCM city,01/01/1998,Engineering,Welcome new member
Note: There is a sample data that I created for testing purpose with file name: sampleData.csv in the folder project Employee Management System.

## Contact
For any questions or issues, please contact the project maintainer at https://github.com/thanhcuong278/Employee_Management.git










