#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 50
#define NAME_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    char department[NAME_LEN];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
} Employee;

void employeeMenu(void);
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void calculateSalaryMenu(void);
float getGrossSalary(Employee e);

int getEmployeeCount(void);
Employee getEmployeeAt(int index);

#endif
