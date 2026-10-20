#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "supplier.h"
#include "assets.h"
#include "reports.h"
#include "utils.h"

static void displayMenu(void) {
    printf("\n========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n\n");
}

int main(void) {
    int choice = 0;

    while (choice != 6) {
        displayMenu();
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: employeeMenu(); break;
            case 2: budgetMenu(); break;
            case 3: supplierMenu(); break;
            case 4: assetMenu(); break;
            case 5: reportsMenu(); break;
            case 6: printf("\nThank you for using MFMS. Goodbye!\n"); break;
            default: printf("Invalid choice. Please enter a number from 1 to 6.\n");
        }
    }

    return 0;
}
