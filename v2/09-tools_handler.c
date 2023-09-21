#include "main.h"
/**
* free2D - Frees memory allocated for a 2D array.
* @arr: The 2D array to be freed.
*
*Description: This function takes 2D array and frees the memory for it.
*/

void free2D(char **arr)
{
int i;
if (!arr)
return;
for (i = 0; arr[i]; i++)
{
free(arr[i]);
arr[i] = NULL;
}
free(arr), arr = NULL;
}
/**
* print_error - Prints an error message to the standard error output.
* @prog: The name of the program.
* @cmd: The name of the command that caused the error.
* @ctr: The command counter.
*
* Description: This function takes the program name, command name,
* and command counter,
* and prints an appropriate error.
*/
void print_error(char *prog, char *cmd, int ctr)
{
char *idx;
char not_found[] = ": not found\n";

idx = int_to_str(ctr);
write(STDERR_FILENO, prog, _strlen(prog));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, idx, _strlen(idx));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, cmd, _strlen(cmd));
write(STDERR_FILENO, not_found, _strlen(not_found));
free(idx);
}
/**
* int_to_str - Converts an integer to a string.
* @n: The input integer.
*
* Return: A dynamically allocated string, or an error.
*/
char *int_to_str(int n)
{
char buff[20];
int i = 0;

if (n == 0)
buff[i++] = '0';
else
{
while (n > 0)
{
buff[i++] = (n % 10) + '0';
n /= 10;
}
}
buff[i] = '\0';
rev_str(buff, i);
return (_strdup(buff));
}

/**
*rev_str - reverse the order of the char in buff array
*@str : a string as its length as input.
*@len: the length of the string to be reverses
*
*Description:  it reverses the order of characters in the string.
*/
void rev_str(char *str, int len)
{
char tmp;
int i = 0;
int end = len - 1; /*due to '\0'*/

while (i < end)
{
tmp = str[i];
str[i] = str[end];
str[end] = tmp;
i++;
end--;
}
}
