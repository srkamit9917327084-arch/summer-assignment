#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void compressString(char *str) {
    int len = strlen(str);
    if (len == 0) return;

    char *compressed = (char *)malloc((len * 2 + 1) * sizeof(char));
    int i, count = 1, j = 0;

    for (i = 0; i < len; i++) {
        if (i + 1 < len && str[i] == str[i + 1]) {
            count++;
        } else {
            j += sprintf(&compressed[j], "%c%d", str[i], count);
            count = 1;
        }
    }

    if (strlen(compressed) < len) {
        strcpy(str, compressed);
    }

    free(compressed);
}

int main() {
    char str[] = "aabcccccaaa";
    
    compressString(str);
    printf("%s\n", str);
    
    return 0;
}