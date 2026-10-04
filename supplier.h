#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 50
#define SUP_LEN 50

typedef struct {
    int id;
    char name[SUP_LEN];
    char email[SUP_LEN];
    char phone[20];
    char town[SUP_LEN];
} Supplier;

void supplierMenu(void);
void addSupplier(void);
void displaySuppliers(void);
void searchSupplier(void);

int getSupplierCount(void);
Supplier getSupplierAt(int index);

#endif
