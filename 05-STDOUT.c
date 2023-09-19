#include "main.h"
int _putchar(char *c)
{
    return (write(1, c, 1));
}
int print_string(char *str)
{
    int i;

    for (i = 0; str[i]; i++)
        _putchar((str + i));

    return (i);
}
void print_env(void)
{
    char **env = environ;
    while (*env != NULL)
    {

        write(1, *env, _strlen(*env));
        write(1, "\n", 1);
        env++;
    }
}