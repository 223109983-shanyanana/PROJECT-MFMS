#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "utils.h"

static Employee employees[MAX_EMPLOYEES];
static int employeeCount = 0;
static int nextEmployeeId = 1;

int getEmployeeCount(void) {
    return employeeCount;
}
Employee getEmployeeAt(int index) {
    return employees[index];
}
float getGrossSalary(Employee e) {
    return e.basicSalary + e.housingAllowance + e.transportAllowance;
}
void addEmployee(void) {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("\nEmployee list is full (max %d). Cannot add more employees.\n", MAX_EMPLOYEES);
        return;
    }

    Employee e;
    e.id = nextEmployeeId;

    printf("\n--- Add Employee ---\n");
    readLine("Enter employee name: ", e.name, NAME_LEN, 1);
    readLine("Enter department: ", e.department, NAME_LEN, 1);
    e.basicSalary = readNonNegativeFloat("Enter basic salary: N$");
    e.housingAllowance = readNonNegativeFloat("Enter housing allowance: N$");
    e.transportAllowance = readNonNegativeFloat("Enter transport allowance: N$");

    employees[employeeCount] = e;
    employeeCount++;
    nextEmployeeId++;

    printf("Employee '%s' added successfully with ID %d.\n", e.name, e.id);
}
void displayEmployees(void) {
    printf("\n--- Employee List ---\n");
    if (employeeCount == 0) {
        printf("No employees recorded yet.\n");
        return;
    }

    printf("%-4s %-20s %-15s %12s %12s %12s %12s\n",
           "ID", "Name", "Department", "Basic", "Housing", "Transport", "Gross");
    for (int i = 0; i < employeeCount; i++) {
        Employee e = employees[i];
        printf("%-4d %-20s %-15s %12.2f %12.2f %12.2f %12.2f\n",
               e.id, e.name, e.department, e.basicSalary,
               e.housingAllowance, e.transportAllowance, getGrossSalary(e));
    }
}
void searchEmployee(void) {
    if (employeeCount == 0) {
        printf("\nNo employees recorded yet.\n");
        return;
    }

    char searchName[NAME_LEN];
    int found = 0;

    readLine("\nEnter employee name to search: ", searchName, NAME_LEN, 1);

    for (int i = 0; i < employeeCount; i++) {
        if (strcmp(employees[i].name, searchName) == 0) {
            Employee e = employees[i];
            printf("\nEmployee found:\n");
            printf("ID: %d\nName: %s\nDepartment: %s\n", e.id, e.name, e.department);
            printf("Basic Salary: N$%.2f\n", e.basicSalary);
            printf("Housing Allowance: N$%.2f\n", e.housingAllowance);
            printf("Transport Allowance: N$%.2f\n", e.transportAllowance);
            printf("Gross Salary: N$%.2f\n", getGrossSalary(e));
            found = 1;
        }
    }

    if (!found) {
        printf("No employee named '%s' was found.\n", searchName);
    }
}
void calculateSalaryMenu(void) {
    if (employeeCount == 0) {
        printf("\nNo employees recorded yet.\n");
        return;
    }

    int id = readInt("\nEnter employee ID to calculate salary for: ");
    int found = 0;

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            Employee e = employees[i];
            printf("\nSalary breakdown for %s (ID %d):\n", e.name, e.id);
            printf("  Basic Salary:        N$%10.2f\n", e.basicSalary);
            printf("  Housing Allowance:   N$%10.2f\n", e.housingAllowance);
            printf("  Transport Allowance: N$%10.2f\n", e.transportAllowance);
            printf("  ------------------------------\n");
            printf("  Gross Salary:        N$%10.2f\n", getGrossSalary(e));
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No employee with ID %d was found.\n", id);
    }
}
void employeeMenu(void) {
    int choice = -1;
    while (choice != 0) {
        printf("\n--- Employee Management ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Calculate Employee Salary\n");
        printf("0. Back to Main Menu\n");
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: calculateSalaryMenu(); break;
            case 0: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}
