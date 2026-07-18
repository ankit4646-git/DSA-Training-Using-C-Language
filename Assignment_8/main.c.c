#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_NAME_LEN 50

// Structure 
typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    double baseSalary;
    double hra;        // House Rent Allowance
    double da;         // Dearness Allowance
    double tax;        // Tax Deduction
    double grossSalary;
    double netSalary;
} Employee;

// Functions Used
void addEmployee(Employee staff[], int *count);
void calculatePayroll(Employee *e);
void displaySalaryReport(const Employee staff[], int count);
void sortEmployeesByNetSalary(Employee staff[], int count);
void clearInputBuffer(void);

int main(void) {
    Employee staff[MAX_EMPLOYEES];
    int count = 0;
    int choice;

    printf("=========================================\n");
    printf("         EMPLOYEE PAYROLL SYSTEM         \n");
    printf("=========================================\n");

    do {
        printf("\n-----------------------------------------\n");
        printf("                 MENU                    \n");
        printf("-----------------------------------------\n");
        printf("1. Add Employee & Compute Payroll\n");
        printf("2. Display Salary Report Ledger\n");
        printf("3. Sort Employees by Net Salary (Descending)\n");
        printf("4. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                addEmployee(staff, &count);
                break;
            case 2:
                displaySalaryReport(staff, count);
                break;
            case 3:
                sortEmployeesByNetSalary(staff, count);
                printf("\nStaff records sorted by Net Salary successfully.\n");
                displaySalaryReport(staff, count);
                break;
            case 4:
                printf("\nExiting system. Payroll transaction caches cleared.\n");
                break;
            default:
                printf("Invalid choice. Please pick an option from 1 to 4.\n");
        }
    } while (choice != 4);

    return 0;
}

/**
 * Registers an employee record a
 * Time Complexity: O(1) baseline, O(N) validation | Space Complexity: O(1)
 */
void addEmployee(Employee staff[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("\nError: Maximum employee ledger registration limit reached (%d).\n", MAX_EMPLOYEES);
        return;
    }

    Employee e;
    printf("\nEnter Employee ID: ");
    while (scanf("%d", &e.id) != 1 || e.id <= 0) {
        printf("Invalid ID. Enter a positive integer: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    // Verify primary key identity constraints
    for (int i = 0; i < *count; i++) {
        if (staff[i].id == e.id) {
            printf("Error: Employee ID %d already exists in database.\n", e.id);
            return;
        }
    }

    printf("Enter Employee Name: ");
    if (scanf("%49[^\n]", e.name) != 1) {
        strcpy(e.name, "Anonymous Staff");
    }
    clearInputBuffer();

    printf("Enter Base Monthly Salary (Rs.): ");
    while (scanf("%lf", &e.baseSalary) != 1 || e.baseSalary < 0.0) {
        printf("Invalid scale. Enter a positive valuation: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    calculatePayroll(&e);

    staff[*count] = e;
    (*count)++;
    printf("Employee registered and payroll computed successfully.\n");
}

/**
 * Executes bracket logic formulas to calculate allowances, gross, and net structures.
 * Time Complexity: O(1) | Space Complexity: O(1)
 */
void calculatePayroll(Employee *e) {
    // Allowance Bracket Configurations
    // HRA = 20% of Base, DA = 10% of Base
    e->hra = e->baseSalary * 0.20;
    e->da = e->baseSalary * 0.10;
    
    e->grossSalary = e->baseSalary + e->hra + e->da;

    // Progressive Bracket Taxation 
    if (e->grossSalary <= 3000.0) {
        e->tax = e->grossSalary * 0.05;  // 5% tax bracket
    } else if (e->grossSalary <= 7000.0) {
        e->tax = e->grossSalary * 0.12;  // 12% tax bracket
    } else {
        e->tax = e->grossSalary * 0.22;  // 22% tax bracket
    }

    e->netSalary = e->grossSalary - e->tax;
}

/**
 * Make a structured financial details table.
 * Time Complexity: O(N) | Space Complexity: O(1)
 */
void displaySalaryReport(const Employee staff[], int count) {
    if (count == 0) {
        printf("\nNo operational employee ledger logs registered.\n");
        return;
    }

    printf("\n--------------------------------------------------------------------------------------------------------\n");
    printf("%-8s | %-20s | %-12s | %-10s | %-10s | %-10s | %-10s | %-12s\n", 
           "ID", "Employee Name", "Base (Rs.)", "HRA (Rs.)", "DA (Rs.)", "Tax (Rs.)", "Gross (Rs.)", "Net (Rs.)");
    printf("--------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-8d | %-20s | %-12.2f | %-10.2f | %-10.2f | %-10.2f | %-10.2f | %-12.2f\n",
               staff[i].id, staff[i].name, staff[i].baseSalary, staff[i].hra, 
               staff[i].da, staff[i].tax, staff[i].grossSalary, staff[i].netSalary);
    }
    printf("--------------------------------------------------------------------------------------------------------\n");
}

/**
 * Sort internal arrays in descending order
 * Time Complexity: O(N^2) | Space Complexity: O(1) auxiliary
 */
void sortEmployeesByNetSalary(Employee staff[], int count) {
    for (int i = 0; i < count - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < count; j++) {
            if (staff[j].netSalary > staff[maxIdx].netSalary) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            Employee temp = staff[i];
            staff[i] = staff[maxIdx];
            staff[maxIdx] = temp;
        }
    }
}

/**
 * Remove leftovers from standard text parsing buffers.
 */
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}