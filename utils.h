#ifndef UTILS_H
#define UTILS_H

/* Clears leftover characters (including the newline) from stdin after a
   scanf() call, so the next read is not corrupted by stray input. */
void clearInputBuffer(void);

/* Reads a line of text into buffer (max size 'size', including the null
   terminator), strips the trailing newline, and re-prompts if the line
   is empty when notEmpty is non-zero. */
void readLine(const char *prompt, char *buffer, int size, int notEmpty);

/* Prompts repeatedly until the user enters a valid, non-negative float. */
float readNonNegativeFloat(const char *prompt);

/* Prompts repeatedly until the user enters a valid integer. */
int readInt(const char *prompt);

#endif
