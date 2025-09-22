// File: src/mystrfunctions.c
#include "../include/mystrfunctions.h"

int mystrlen(const char* s) {
    // Count and return the length of string s
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}

int mystrcpy(char* dest, const char* src) {
    // Copy string from src to dest, return 0 on success
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return 0;
}

int mystrncpy(char* dest, const char* src, int n) {
    // Copy up to n chars from src to dest
    int i = 0;
    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    if (i < n) {
        dest[i] = '\0';
    }
    return 0;
}

int mystrcat(char* dest, const char* src) {
    // Append src to the end of dest
    int dest_len = mystrlen(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return 0;
}
