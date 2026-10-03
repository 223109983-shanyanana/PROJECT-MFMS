#include <stdio.h>
#include <string.h>
#include "utils.h"

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* discard */
    }
}

void readLine(const char *prompt, char *buffer, int size, int notEmpty) {
    int valid = 0;
    while (!valid) {
        printf("%s", prompt);
        if (fgets(buffer, size, stdin) == NULL) {
            buffer[0] = '\0';
            return;
        }
        /* strip trailing newline, if present */
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        } else {
            /* line was longer than the buffer: flush the rest of it */
            clearInputBuffer();
        }
        if (notEmpty && strlen(buffer) == 0) {
            printf("Input cannot be empty. Please try again.\n");
        } else {
            valid = 1;
        }
    }
}

float readNonNegativeFloat(const char *prompt) {
    float value;
    int valid = 0;
    while (!valid) {
        printf("%s", prompt);
        if (scanf("%f", &value) != 1) {
            printf("Invalid number. Please try again.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();
        if (value < 0) {
            printf("Value cannot be negative. Please try again.\n");
            continue;
        }
        valid = 1;
    }
    return value;
}

int readInt(const char *prompt) {
    int value;
    int valid = 0;
    while (!valid) {
        printf("%s", prompt);
        if (scanf("%d", &value) != 1) {
            printf("Invalid choice. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();
        valid = 1;
    }
    return value;
}
