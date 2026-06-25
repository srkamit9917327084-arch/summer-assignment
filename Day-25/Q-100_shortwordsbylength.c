#include <stdio.h>
#include <string.h>

void sortNames(char names[][50], int n) {
    char temp[50];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }
}

int main() {
    char names[][50] = {
        "Zendaya",
        "Alice",
        "Bob",
        "Oliver",
        "Charlie"
    };
    int n = sizeof(names) / sizeof(names[0]);

    sortNames(names, n);

    printf("Names in alphabetical order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}