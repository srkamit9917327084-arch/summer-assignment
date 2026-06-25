#include <stdio.h>
#include <string.h>
#include <ctype.h>

void findLongestWord(char *str, char *longest) {
    int maxLen = 0;
    int currLen = 0;
    int startIdx = 0;
    int maxStartIdx = 0;
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] != '\0' && (isspace(str[i]) || ispunct(str[i]))) {
            i++;
        }

        if (str[i] == '\0') break;

        startIdx = i;
        currLen = 0;

        while (str[i] != '\0' && !isspace(str[i]) && !ispunct(str[i])) {
            currLen++;
            i++;
        }

        if (currLen > maxLen) {
            maxLen = currLen;
            maxStartIdx = startIdx;
        }
    }

    strncpy(longest, &str[maxStartIdx], maxLen);
    longest[maxLen] = '\0'; 
}

int main() {
    char str[] = "Gl is best collage in greater noida.";
    char longest[100];

    findLongestWord(str, longest);

    printf("The longest word is: %s\n", longest);

    return 0;
}