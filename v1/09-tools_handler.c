#include "main.h"
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
    free(arr);
}
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