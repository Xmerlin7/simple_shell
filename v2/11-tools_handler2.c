#include "main.h"
/**
 * is_positive - Checks if a string represents a positive number.
 * @str: Null-terminated string to check.
 * Return: 1 if the string represents a positive number, 0 otherwise.
 */

int is_positive(char *str)
{
int i;

if (!str)
return (0);
for (i = 0; *(str + i); i++)
{
if (str[i] < '0' || str[i] > '9')
return (0);
}
return (1);
}
/**
 * str_to_int - Converts a string to an integer.
 * @str: Null-terminated string to convert.
 * Return: The integer representation of the string,
 * or -1 if the string cannot be converted.
 */

int str_to_int(char *str)
{
int i;
int n = 0;

for (i = 0; str[i]; i++)
{
n *= 10;
n += (str[i] - '0');
}
return (n);
}
