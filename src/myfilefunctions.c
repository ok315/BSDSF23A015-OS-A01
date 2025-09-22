#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/myfilefunctions.h"

// Count the number of lines, words, and characters in the passed file stream pointer.
// Return 0 on success and -1 on failure.
int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (file == NULL || lines == NULL || words == NULL || chars == NULL) {
        return -1; // invalid input
    }

    int c;
    int in_word = 0;
    *lines = 0;
    *words = 0;
    *chars = 0;

    // rewind file to start (important if file pointer is not at start)
    rewind(file);

    while ((c = fgetc(file)) != EOF) {
        (*chars)++;

        if (c == '\n') {
            (*lines)++;
        }

        // check word boundaries: word is sequence of non-whitespace chars
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v') {
            in_word = 0;
        } else if (in_word == 0) {
            in_word = 1;
            (*words)++;
        }
    }

    return 0;
}

// Search lines containing search_str in a file, and fills the matches array.
// Return the count of matches and -1 on failure.
// matches is a pointer to an array of strings (char**), dynamically allocated.
int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (fp == NULL || search_str == NULL || matches == NULL) {
        return -1;
    }

    rewind(fp);

    size_t matches_size = 10;  // initial size for matches array
    size_t count = 0;
    *matches = malloc(matches_size * sizeof(char*));
    if (*matches == NULL) {
        return -1;
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, search_str) != NULL) {
            // Found a matching line, add to matches
            if (count >= matches_size) {
                // Resize array if needed
                matches_size *= 2;
                char** temp = realloc(*matches, matches_size * sizeof(char*));
                if (temp == NULL) {
                    // Free already allocated memory before returning
                    for (size_t i = 0; i < count; i++) {
                        free((*matches)[i]);
                    }
                    free(*matches);
                    free(line);
                    return -1;
                }
                *matches = temp;
            }

            // Duplicate the line string and store it
            (*matches)[count] = strdup(line);
            if ((*matches)[count] == NULL) {
                // Free already allocated memory before returning
                for (size_t i = 0; i < count; i++) {
                    free((*matches)[i]);
                }
                free(*matches);
                free(line);
                return -1;
            }
            count++;
        }
    }

    free(line);
    return (int)count;
}
