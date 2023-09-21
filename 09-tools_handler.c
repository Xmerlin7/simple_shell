#include "main.h"

/**
*free2D - free memory allocation for two-dimensional array
*@arr : array of string to be memory free
*return : arr on success , NULL if error
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
 *print_error -prints error message to std error output
 *@prog : program name
 *@cmd : command name
 *@ctr : counter
 *return : func on success , error if failure
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
*int_to_str - converts an integer to string represention
*@n : takes an integer as input 
*buff - store the digits of the integer in reverse order
*return : dynamically allocation string , otherwise error
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
*@str : a string as its length as input
*return : it reverses the order of characters in the string.
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
