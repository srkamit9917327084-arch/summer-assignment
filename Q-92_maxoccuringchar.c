#include <stdio.h>
#include <string.h>

char getMaxOccurringChar(char* str) {
    int count[256] = {0};
    int max = -1;
    char result = '\0';
    
    for (int i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && max < count[(unsigned char)str[i]]) {
            max = count[(unsigned char)str[i]];
            result = str[i];
        }
    }
    
    return result;
}

int main() {
    char str1[] = "My name is amit yadav";
    char str2[] = "Gl bajaj in greater noida";

    printf("String: \"%s\" -> Max occurring character: '%c'\n", str1, getMaxOccurringChar(str1));
    printf("String: \"%s\" -> Max occurring character: '%c'\n", str2, getMaxOccurringChar(str2));

    return 0;
}