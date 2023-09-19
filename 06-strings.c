#include "main.h"

int _strlen(char *str)
{
    int len;

    for (len = 0; *(str + len); len++)
        ;
    return (len + 1);
}
char *_strcpy(char *dest, char *src)
{
    int i;

    for (i = 0; *(src + i) != '\0'; i++)
    {
        *(dest + i) = *(src + i);
    }
    *(dest + i) = '\0';

    return (dest);
}
char *_strdup(char *str)
{
    char *tmp = NULL;
    int ctr = 0;
    if (!str)
        return (NULL);
    ctr = _strlen(str);
    tmp = (char *)malloc(ctr);
    _strcpy(tmp, str);
    return (tmp);
}
int _strcmp(char *str1, char *str2)
{
    int i, ret;

    for (i = 0; *(str1 + i) || *(str2 + i); i++)
    {
        ret = *(str1 + i) - *(str2 + i);
        if (ret != 0)
            break;
    }
    return (ret);
}
char *_strcat(char *destination, const char *source)
{
    char *ptr = destination + strlen(destination);

    while (*source != '\0')
    {
        *ptr++ = *source++;
    }

    *ptr = '\0';

    return destination;
}
