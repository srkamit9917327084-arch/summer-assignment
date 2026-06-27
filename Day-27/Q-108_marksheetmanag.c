#include <stdio.h>

typedef struct {
    int rollNo;
    char name[50];
    float marks[3]; // Assuming 3 subjects
    float total;
    float average;
    char grade;
} Student;

void generateMarksheet() {
    Student s;
    s.total = 0;

    printf("Enter Roll No: ");
    scanf("%d", &s.rollNo);
    printf("Enter Name: ");
    scanf("%s", s.name);

    for(int i = 0; i < 3; i++) {
        printf("Enter marks for Subject %d: ", i + 1);
        scanf("%f", &s.marks[i]);
        s.total += s.marks[i];
    }

    s.average = s.total / 3;

    // Grade logic
    if (s.average >= 90) s.grade = 'A';
    else if (s.average >= 75) s.grade = 'B';
    else if (s.average >= 50) s.grade = 'C';
    else s.grade = 'F';

    printf("\n--- Marksheet ---\n");
    printf("Student: %s (Roll: %d)\n", s.name, s.rollNo);
    printf("Total: %.2f | Average: %.2f\n", s.total, s.average);
    printf("Grade: %c\n", s.grade);
    printf("Status: %s\n", (s.grade == 'F') ? "FAIL" : "PASS");
    printf("-----------------\n");
}

int main() {
    int choice;
    do {
        printf("\n1. Generate Marksheet\n2. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) generateMarksheet();
    } while (choice != 2);
    
    return 0;
}