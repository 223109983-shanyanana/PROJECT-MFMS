#include <string.h>
#include "validation.h"

int isValidMenuChoice(int choice, int minimum, int maximum)
{
    return choice >= minimum && choice <= maximum;
}

int isValidPositiveDouble(double value)
{
    return value >= 0;
}

int isValidPositiveInt(int value)
{
    return value >= 0;
}

int isEmptyString(const char *text)
{
    return text == NULL || strlen(text) == 0;
}
