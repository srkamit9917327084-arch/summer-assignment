#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float baseSalary;
    float bonus;
    float tax;
} SalaryRecord;

void calculateSalary() {
    SalaryRecord emp;
    float netSalary;

    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Name: ");
    scanf("%s", emp.name);
    printf("Enter Base Salary: ");
    scanf("%f", &emp.baseSalary);
    printf("Enter Bonus: ");
    scanf("%f", &emp.bonus);
    printf("Enter Tax Deduction: ");
    scanf("%f", &emp.tax);

    // Calculation Logic
    netSalary = (emp.baseSalary + emp.bonus) - emp.tax;

    printf("\n--- Salary Slip ---\n");
    printf("Employee: %s (ID: %d)\n", emp.name, emp.id);
    printf("Gross: %.2f | Net Salary: %.2f\n", (emp.baseSalary + emp.bonus), netSalary);
    printf("-------------------\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Generate Salary Slip\n2. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            calculateSalary();
        } else {
            break;
        }
    }
    return 0;
}