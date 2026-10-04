#ifndef BUDGET_H
#define BUDGET_H

#define MAX_BUDGETS 20
#define DEPT_LEN 50

typedef struct {
    char department[DEPT_LEN];
    float allocatedBudget;
    float expenditure;
} Budget;

void budgetMenu(void);
void addBudget(void);
void displayBudgets(void);
float getRemainingBudget(Budget b);
int isWithinBudget(Budget b);

int getBudgetCount(void);
Budget getBudgetAt(int index);

#endif
