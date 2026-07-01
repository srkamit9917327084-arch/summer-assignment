#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100
#define AUTHOR_LEN 50

typedef struct {
    int bookID;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int isAvailable; // 1 for available, 0 for borrowed
} Book;

// Function Prototypes
void addBook(Book library[], int *count);
void displayLibrary(Book library[], int count);
void searchBook(Book library[], int count);

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    while (1) {
        printf("\n--- Mini Library System ---\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by Title\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(library, &bookCount); break;
            case 2: displayLibrary(library, bookCount); break;
            case 3: searchBook(library, bookCount); break;
            case 4: return 0;
            default: printf("Invalid option.\n");
        }
    }
}

void addBook(Book library[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }
    printf("Enter ID: ");
    scanf("%d", &library[*count].bookID);
    while (getchar() != '\n'); // Clear buffer

    printf("Enter Title: ");
    fgets(library[*count].title, TITLE_LEN, stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = 0;

    printf("Enter Author: ");
    fgets(library[*count].author, AUTHOR_LEN, stdin);
    library[*count].author[strcspn(library[*count].author, "\n")] = 0;

    library[*count].isAvailable = 1;
    (*count)++;
    printf("Book added!\n");
}

void displayLibrary(Book library[], int count) {
    printf("\n%-5s %-30s %-20s %-10s\n", "ID", "Title", "Author", "Status");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-30s %-20s %-10s\n", 
            library[i].bookID, library[i].title, library[i].author, 
            library[i].isAvailable ? "Available" : "Borrowed");
    }
}

void searchBook(Book library[], int count) {
    char searchTitle[TITLE_LEN];
    int found = 0;
    printf("Enter title to search: ");
    while (getchar() != '\n');
    fgets(searchTitle, TITLE_LEN, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;

    for (int i = 0; i < count; i++) {
        if (strcasecmp(library[i].title, searchTitle) == 0) {
            printf("Found: ID %d, Author: %s\n", library[i].bookID, library[i].author);
            found = 1;
        }
    }
    if (!found) printf("Book not found.\n");
}