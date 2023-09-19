#include "main.h"

/**
 * readline - reads a line of input string
 * 
 * @line : return value of isatty func.
 * RETURN : input string
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
