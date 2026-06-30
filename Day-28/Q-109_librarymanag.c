#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
};

void addBook() {
    FILE *fp = fopen("library.dat", "ab");
    struct Book b;
    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    printf("Enter Title: ");
    scanf("%s", b.title);
    printf("Enter Author: ");
    scanf("%s", b.author);
    
    fwrite(&b, sizeof(struct Book), 1, fp);
    fclose(fp);
    printf("Book added successfully!\n");
}

void displayBooks() {
    FILE *fp = fopen("library.dat", "rb");
    struct Book b;
    printf("\n--- Library Books ---\n");
    while(fread(&b, sizeof(struct Book), 1, fp)) {
        printf("ID: %d | Title: %s | Author: %s\n", b.id, b.title, b.author);
    }
    fclose(fp);
}

int main() {
    int choice;
    while(1) {
        printf("\n1. Add Book\n2. View Books\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}