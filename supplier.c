#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "utils.h"

static Supplier suppliers[MAX_SUPPLIERS];
static int supplierCount = 0;
static int nextSupplierId = 1;

int getSupplierCount(void) {
    return supplierCount;
}

Supplier getSupplierAt(int index) {
    return suppliers[index];
}

void addSupplier(void) {
    if (supplierCount >= MAX_SUPPLIERS) {
        printf("\nSupplier list is full (max %d). Cannot add more suppliers.\n", MAX_SUPPLIERS);
        return;
    }

    Supplier s;
    s.id = nextSupplierId;

    printf("\n--- Add Supplier ---\n");
    readLine("Enter supplier name: ", s.name, SUP_LEN, 1);
    readLine("Enter email: ", s.email, SUP_LEN, 1);
    readLine("Enter telephone number: ", s.phone, 20, 1);
    readLine("Enter town/location: ", s.town, SUP_LEN, 1);

    suppliers[supplierCount] = s;
    supplierCount++;
    nextSupplierId++;

    printf("Supplier '%s' added successfully with ID %d.\n", s.name, s.id);
}

void displaySuppliers(void) {
    printf("\n--- Supplier List ---\n");
    if (supplierCount == 0) {
        printf("No suppliers recorded yet.\n");
        return;
    }

    printf("%-4s %-20s %-25s %-15s %-15s\n",
           "ID", "Name", "Email", "Phone", "Town");
    for (int i = 0; i < supplierCount; i++) {
        Supplier s = suppliers[i];
        printf("%-4d %-20s %-25s %-15s %-15s\n",
               s.id, s.name, s.email, s.phone, s.town);
    }
}

/* Searches suppliers by name (strcmp) or by town, so the user can either
   look up a specific supplier or compare all suppliers in one area. */
void searchSupplier(void) {
    if (supplierCount == 0) {
        printf("\nNo suppliers recorded yet.\n");
        return;
    }

    printf("\nSearch by:\n1. Supplier Name\n2. Town/Location\n");
    int option = readInt("Enter your choice: ");

    char query[SUP_LEN];
    int found = 0;

    if (option == 1) {
        readLine("Enter supplier name: ", query, SUP_LEN, 1);
        for (int i = 0; i < supplierCount; i++) {
            if (strcmp(suppliers[i].name, query) == 0) {
                Supplier s = suppliers[i];
                printf("\nID: %d\nName: %s\nEmail: %s\nPhone: %s\nTown: %s\n",
                       s.id, s.name, s.email, s.phone, s.town);
                found = 1;
            }
        }
    } else if (option == 2) {
        readLine("Enter town/location: ", query, SUP_LEN, 1);
        printf("\nSuppliers in %s:\n", query);
        for (int i = 0; i < supplierCount; i++) {
            if (strcmp(suppliers[i].town, query) == 0) {
                Supplier s = suppliers[i];
                printf("ID: %d | Name: %s | Email: %s | Phone: %s\n",
                       s.id, s.name, s.email, s.phone);
                found = 1;
            }
        }
    } else {
        printf("Invalid search option.\n");
        return;
    }

    if (!found) {
        printf("No matching suppliers were found.\n");
    }
}

void supplierMenu(void) {
    int choice = -1;
    while (choice != 0) {
        printf("\n--- Supplier Management ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("0. Back to Main Menu\n");
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: addSupplier(); break;
            case 2: displaySuppliers(); break;
            case 3: searchSupplier(); break;
            case 0: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}
