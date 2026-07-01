#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float gpa;
} Student;

void addStudent(Student students[], int *count);
void displayStudents(Student students[], int count);

int main() {
    Student classRoom[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    while (1) {
        printf("\n--- Student Record System ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(classRoom, &studentCount);
                break;
            case 2:
                displayStudents(classRoom, studentCount);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("System full! Cannot add more students.\n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &students[*count].id);
    
    printf("Enter Name: ");
    // Clear buffer before reading string
    while (getchar() != '\n'); 
    fgets(students[*count].name, NAME_LENGTH, stdin);
    // Remove newline character added by fgets
    students[*count].name[strcspn(students[*count].name, "\n")] = 0;

    printf("Enter GPA: ");
    scanf("%f", &students[*count].gpa);

    (*count)++;
    printf("Student added successfully!\n");
}

void displayStudents(Student students[], int count) {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\n%-10s %-20s %-10s\n", "ID", "Name", "GPA");
    printf("------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}