#include "main.h"
int is_positive(char *str)
{
    int i;

    if (!str)
        return (0);
    for (i = 0; str[i]; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}
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