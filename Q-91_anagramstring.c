#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isAnagram(char* str1, char* str2) {
    int count[256] = {0};
    
    if (strlen(str1) != strlen(str2)) {
        return false;
    }
    
    for (int i = 0; str1[i] != '\0'; i++) {
        count[(unsigned char)str1[i]]++;
        count[(unsigned char)str2[i]]--;
    }
    
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    char s1[] = "listen";
    char s2[] = "silent";
    char s3[] = "hello";
    char s4[] = "world";

    printf("\"%s\" and \"%s\" are %s\n", s1, s2, isAnagram(s1, s2) ? "Anagrams" : "Not Anagrams");
    printf("\"%s\" and \"%s\" are %s\n", s3, s4, isAnagram(s3, s4) ? "Anagrams" : "Not Anagrams");

    return 0;
}