#include <stdio.h>
#include <string.h>

void findCommonCharacters(char strings[][100], int n) {
    int min_freq[26];
    for (int i = 0; i < 26; i++) {
        min_freq[i] = 1000; 
    }

    for (int i = 0; i < n; i++) {
        int count[26] = {0};
        for (int j = 0; strings[i][j] != '\0'; j++) {
            if (strings[i][j] >= 'a' && strings[i][j] <= 'z') {
                count[strings[i][j] - 'a']++;
            }
        }

        for (int j = 0; j < 26; j++) {
            if (count[j] < min_freq[j]) {
                min_freq[j] = count[j];
            }
        }
    }

    printf("Common characters: ");
    int found = 0;
    for (int i = 0; i < 26; i++) {
        while (min_freq[i] > 0 && min_freq[i] != 1000) {
            printf("%c ", i + 'a');
            min_freq[i]--;
            found = 1;
        }
    }
    
    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    char strings[][100] = {
        "bella",
        "label",
        "roller"
    };
    int n = sizeof(strings) / sizeof(strings[0]);

    findCommonCharacters(strings, n);

    return 0;
}