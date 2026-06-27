#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void addEmployee() {
    FILE *fp = fopen("employees.dat", "ab");
    Employee emp;

    printf("Enter ID: ");
    scanf("%d", &emp.id);
    printf("Enter Name: ");
    scanf("%s", emp.name);
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(Employee), 1, fp);
    fclose(fp);
    printf("Employee added successfully!\n");
}

void viewEmployees() {
    FILE *fp = fopen("employees.dat", "rb");
    Employee emp;

    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\n--- Employee List ---\n");
    while (fread(&emp, sizeof(Employee), 1, fp)) {
        printf("ID: %d | Name: %s | Salary: %.2f\n", emp.id, emp.name, emp.salary);
    }
    fclose(fp);
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Employee\n2. View Employees\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}