#include <stdio.h>
#include <string.h>

char findFirstRepeating(char* str) {
    int count[256] = {0};
    
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str[i];
        
        if (count[ch] == 1) {
            return str[i];
        }
        
        count[ch]++;
    }
    
    return '\0'; 
}

int main() {
    char str1[] = "greater";
    char str2[] = "bajaj";
    char str3[] = "swiss";

    char result1 = findFirstRepeating(str1);
    char result2 = findFirstRepeating(str2);
    char result3 = findFirstRepeating(str3);

    printf("String: \"%s\" -> First repeating: %c\n", str1, result1 ? result1 : '-');
    printf("String: \"%s\" -> First repeating: %c\n", str2, result2 ? &result2 : '-');
    printf("String: \"%s\" -> First repeating: %c\n", str3, result3 ? result3 : '-');

    return 0;
}