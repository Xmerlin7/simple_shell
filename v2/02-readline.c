#include "main.h"
/**
* read_line - Reads a line of input from the standard input.
*
* Description: This function reads a line of input from the stdin,
* typically provided by the user.
*
* Return: A pointer to the line read, or NULL on failure or end of file.
*/
char *read_line(void)
{
char *line = NULL;
size_t len = 0;
ssize_t n = 0;

if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);
n = getline(&line, &len, stdin);
if (n == -1)
{
free(line);
return (NULL);
}
return (line);
}
