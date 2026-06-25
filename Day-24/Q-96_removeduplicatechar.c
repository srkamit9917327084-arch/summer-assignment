#include <stdio.h>
#include <string.h>

void removeDuplicates(char *str) {
    int len = strlen(str);
    if (len < 2) return;

    int seen[256] = {0}; 
    int targetIndex = 0; 

    for (int currentIndex = 0; currentIndex < len; currentIndex++) {
        unsigned char ch = str[currentIndex];
        
        if (seen[ch] == 0) {
            seen[ch] = 1; 
            str[targetIndex] = str[currentIndex];
            targetIndex++;
        }
    }
    
    str[targetIndex] = '\0';
}

int main() {
    char str[] = "programming";
    
    printf("Original string: %s\n", str);
    removeDuplicates(str);
    printf("String after removing duplicates: %s\n", str);
    
    return 0;
}