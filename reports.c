#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "utils.h"

void employeeReport(void) {
    int count = getEmployeeCount();
    printf("\n--- Employee Report ---\n");
    if (count == 0) {
        printf("No employees recorded yet.\n");
        return;
    }

    float total = 0.0f, highest, lowest;
    highest = lowest = getGrossSalary(getEmployeeAt(0));

    for (int i = 0; i < count; i++) {
        float gross = getGrossSalary(getEmployeeAt(i));
        total += gross;
        if (gross > highest) highest = gross;
        if (gross < lowest) lowest = gross;
    }

    printf("Total Employees: %d\n", count);
    printf("Average Salary: N$%.2f\n", total / count);
    printf("Highest Salary: N$%.2f\n", highest);
    printf("Lowest Salary: N$%.2f\n", lowest);
}

void budgetReport(void) {
    int count = getBudgetCount();
    printf("\n--- Budget Report ---\n");
    if (count == 0) {
        printf("No budgets recorded yet.\n");
        return;
    }

    float totalAllocated = 0.0f, totalExpenditure = 0.0f;
    int overBudgetCount = 0;

    for (int i = 0; i < count; i++) {
        Budget b = getBudgetAt(i);
        totalAllocated += b.allocatedBudget;
        totalExpenditure += b.expenditure;
        if (!isWithinBudget(b)) {
            overBudgetCount++;
        }
    }

    printf("Total Allocated Budget: N$%.2f\n", totalAllocated);
    printf("Total Expenditure:      N$%.2f\n", totalExpenditure);
    printf("Total Remaining Budget: N$%.2f\n", totalAllocated - totalExpenditure);

    printf("\nDepartments Exceeding Budget:\n");
    if (overBudgetCount == 0) {
        printf("  None. All departments are within budget.\n");
    } else {
        for (int i = 0; i < count; i++) {
            Budget b = getBudgetAt(i);
            if (!isWithinBudget(b)) {
                printf("  %s (over by N$%.2f)\n", b.department, -getRemainingBudget(b));
            }
        }
    }
}

void supplierReport(void) {
    int count = getSupplierCount();
    printf("\n--- Supplier Report ---\n");
    if (count == 0) {
        printf("No suppliers recorded yet.\n");
        return;
    }

    printf("Total Suppliers Registered: %d\n\n", count);
    for (int i = 0; i < count; i++) {
        Supplier s = getSupplierAt(i);
        printf("ID: %-4d Name: %-20s Town: %s\n", s.id, s.name, s.town);
    }
}

void assetReport(void) {
    int count = getAssetCount();
    printf("\n--- Asset Report ---\n");
    if (count == 0) {
        printf("No assets recorded yet.\n");
        return;
    }

    float totalValue = 0.0f;
    for (int i = 0; i < count; i++) {
        totalValue += getAssetAt(i).purchaseValue;
    }

    printf("Total Assets Registered: %d\n", count);
    printf("Total Asset Value: N$%.2f\n\n", totalValue);
    for (int i = 0; i < count; i++) {
        Asset a = getAssetAt(i);
        printf("ID: %-4d Name: %-18s Type: %-12s Value: N$%.2f\n",
               a.id, a.name, a.type, a.purchaseValue);
    }
}

void reportsMenu(void) {
    int choice = -1;
    while (choice != 0) {
        printf("\n--- Reports ---\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("0. Back to Main Menu\n");
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: employeeReport(); break;
            case 2: budgetReport(); break;
            case 3: supplierReport(); break;
            case 4: assetReport(); break;
            case 0: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}
