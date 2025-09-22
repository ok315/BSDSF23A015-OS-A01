#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("---------- Testing String Functions ----------\n");

    // mystrlen
    const char* testStr = "Hello, OS!";
    int len = mystrlen(testStr);
    printf("mystrlen: '%s' => %d characters\n", testStr, len);

    // mystrcpy
    char src1[] = "C is fun!";
    char dest1[50];
    mystrcpy(dest1, src1);
    printf("mystrcpy: src='%s' => dest='%s'\n", src1, dest1);

    // mystrncpy
    char src2[] = "Hello, World!";
    char dest2[50];
    mystrncpy(dest2, src2, 5);
    dest2[5] = '\0';  // manually null-terminate
    printf("mystrncpy (n=5): src='%s' => dest='%s'\n", src2, dest2);

    // mystrcat
    char str1[100] = "Operating ";
    char str2[] = "Systems";
    mystrcat(str1, str2);
    printf("mystrcat: '%s'\n", str1);

    printf("\n---------- Testing File Functions ----------\n");

    FILE *file = fopen("data/testfile.txt", "r");
    if (!file) {
        perror("Failed to open testfile.txt");
        return 1;
    }

    // wordCount
    int lines = 0, words = 0, chars = 0;
    int wc_result = wordCount(file, &lines, &words, &chars);
    if (wc_result == 0) {
        printf("wordCount: Lines = %d, Words = %d, Characters = %d\n", lines, words, chars);
    } else {
        printf("wordCount: Failed\n");
    }
    fclose(file);

    // mygrep
    file = fopen("data/testfile.txt", "r");
    if (!file) {
        perror("Failed to reopen testfile.txt");
        return 1;
    }

    char **matches = NULL;
    int match_count = mygrep(file, "search", &matches);
    if (match_count >= 0) {
        printf("mygrep: Found %d matching lines:\n", match_count);
        for (int i = 0; i < match_count; i++) {
            printf("  - %s", matches[i]);  // newline is already in the line
            free(matches[i]);
        }
        free(matches);
    } else {
        printf("mygrep: Search failed\n");
    }
    fclose(file);

    return 0;
}
