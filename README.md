# PROJECT-MFMS
Group Project A

Group numbers: 7
Group members:
1. Victoria Kambonde, 224090119: Role= Reports
2. Shigwedha Evelina, 224073931: Role= Asset Management 
3. Shiwa-Ovanhu Iitula, 224079255: Role= Budget Management
4. Indongo Lianna, 225014416: Role= Supplier Management
5. Joel Lydia, 224091417 : Role= Employee Management
6. Honest Haimbangu, 224073370: Role= Functions, intergration and validation
7. Ndidalela Rahya Sh, 223109983: Role= Testing, documentation and Git coordination

8. Group desscription:

The MFMS is a menu-driven console application written in ANSI C (C99) that
gives a municipality a foundation system for managing employees, department
budgets, suppliers and municipal assets, with basic reporting across all
four areas. It was built to demonstrate variables, operators,
decision-making, loops, arrays, strings and functions as covered in Weeks
1–8 of PAP521S.

System Features

- Employee Management – add, display, search (by name) and calculate
  the salary breakdown (basic + housing + transport allowance) of employees.
- Budget Management – record a department's allocated budget and
  expenditure, calculate the remaining balance, and flag departments that
  are over budget.
- Supplier Management – add, display and search suppliers by name or
  by town/location.
- Asset Management – maintain a register of municipal assets (vehicles,
  computers, buildings, equipment, furniture) and search by asset type.
- Reports – summary reports for employees (total, average, highest,
  lowest salary), budgets (totals and departments exceeding budget),
  suppliers and assets.
- Input validation – negative salaries/budgets/values are rejected,
  empty names are rejected, and invalid menu choices are handled without
  crashing the program.

File Structure

```
MFMS/
├── main.c          Main menu and program entry point
├── employees.c/.h   Employee Management module
├── budget.c/.h      Budget Management module
├── suppliers.c/.h   Supplier Management module
├── assets.c/.h      Asset Management module
├── reports.c/.h     Reports module (reads data via getters from the other modules)
├── utils.c/.h       Shared input-reading and validation helpers
└── README.md

Each module keeps its own data (as a `static` array local to its `.c`
file) and exposes it to the rest of the program only through getter
functions (e.g. `getEmployeeCount()`, `getEmployeeAt()`), so `reports.c`
can build cross-module reports without any module needing global
variables.

## Compilation Instructions

From inside the `MFMS/` folder, using GCC:

```bash
gcc -std=c99 -Wall -Wextra -o mfms main.c employees.c budget.c suppliers.c assets.c reports.c utils.c
```

This has been compiled and tested with GCC (Ubuntu 13.3.0) with zero
warnings under `-Wall -Wextra`.

How to Run

```bash
./mfms
```

On Windows (e.g. Visual Studio Code with MinGW), compile the same way and
run `mfms.exe`.

Use the on-screen menu to navigate between Employee Management, Budget
Management, Supplier Management, Asset Management and Reports. Enter `0`
from any sub-menu to return to the main menu, and `6` from the main menu
to exit.

Individual Responsibilities

- Victoria Kambonde – Designed and implemented `reports.c`/`.h`: the
  employee, budget, supplier and asset summary reports.
- Shigwedha Evelina – Designed and implemented `assets.c`/`.h`: the
  municipal asset register and type-based search.
- Shiwovanhu Iitula – Designed and implemented `budget.c`/`.h`:
  recording departmental budgets/expenditure and flagging over-budget
- Indongo Lianna – Designed and implemented `suppliers.c`/`.h`:
  adding, displaying and searching suppliers by name or town.
- Joel Lydia – Designed and implemented `employees.c`/`.h`:
  adding, displaying, searching and calculating salaries for employees.
- Honest Haimbangu – Implemented `utils.c`/`.h` (shared input
  validation helpers) and `main.c`, integrating every module's menu
  into the top-level Main Menu.
- Ndidalela Rahya Sh – Led testing of the integrated system,
  authored `README.md` and the technical report, and coordinated the
  GitHub repository and commit history.

This maps directly onto the 7-role breakdown recommended in the
assignment brief (Section 12).
