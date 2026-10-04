#include <stdio.h>
#include <string.h>
#include "budget.h"
#include "utils.h"

static Budget budgets[MAX_BUDGETS];
static int budgetCount = 0;

int getBudgetCount(void) {
    return budgetCount;
}

Budget getBudgetAt(int index) {
    return budgets[index];
}

float getRemainingBudget(Budget b) {
    return b.allocatedBudget - b.expenditure;
}

int isWithinBudget(Budget b) {
    return b.expenditure <= b.allocatedBudget;
}

/* Adds a department budget, or updates it in place if the department
   already exists (found via strcmp), so the list never duplicates a
   department name. */
void addBudget(void) {
    char department[DEPT_LEN];
    readLine("\nEnter department name: ", department, DEPT_LEN, 1);

    for (int i = 0; i < budgetCount; i++) {
        if (strcmp(budgets[i].department, department) == 0) {
            printf("Department '%s' already has a budget entry. Updating it.\n", department);
            budgets[i].allocatedBudget = readNonNegativeFloat("Enter allocated budget: N$");
            budgets[i].expenditure = readNonNegativeFloat("Enter expenditure: N$");
            return;
        }
    }

    if (budgetCount >= MAX_BUDGETS) {
        printf("Budget list is full (max %d departments).\n", MAX_BUDGETS);
        return;
    }

    Budget b;
    strcpy(b.department, department);
    b.allocatedBudget = readNonNegativeFloat("Enter allocated budget: N$");
    b.expenditure = readNonNegativeFloat("Enter expenditure: N$");

    budgets[budgetCount] = b;
    budgetCount++;

    printf("Budget for '%s' recorded successfully.\n", department);
}

void displayBudgets(void) {
    printf("\n--- Departmental Budgets ---\n");
    if (budgetCount == 0) {
        printf("No budgets recorded yet.\n");
        return;
    }

    printf("%-15s %14s %14s %14s %15s\n",
           "Department", "Allocated", "Expenditure", "Remaining", "Status");
    for (int i = 0; i < budgetCount; i++) {
        Budget b = budgets[i];
        printf("%-15s %14.2f %14.2f %14.2f %15s\n",
               b.department, b.allocatedBudget, b.expenditure,
               getRemainingBudget(b),
               isWithinBudget(b) ? "WITHIN BUDGET" : "OVER BUDGET");
    }
}

void budgetMenu(void) {
    int choice = -1;
    while (choice != 0) {
        printf("\n--- Budget Management ---\n");
        printf("1. Add / Update Departmental Budget\n");
        printf("2. Display Budgets\n");
        printf("0. Back to Main Menu\n");
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: addBudget(); break;
            case 2: displayBudgets(); break;
            case 0: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}
