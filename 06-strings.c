#include "main.h"

/**
 * _strlen - return the length of a string
 * @str : the string wants to check its length
 * 
 * RETURN : int length of string
*/

int _strlen(char *str)
{
    int len;

    for (len = 0; *(str + len); len++)
        ;
    return (len + 1);
}

/**
 * _strcpy - copies a string
 * @dest : the destination
 * @sec : the source
 * 
 * RETURN : pointer to destination
*/

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

/**
 * _strdup - duplicates a string
 * @str : the string to be dplicated
 * 
 * RETURN : refer to duplicated string
*/

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
/**
 * _strcmp - make comparision of two strings
 * @str1 : first string
 * @str2 :second string
 * 
 * RETURN : ret if it is not equal to NULL
*/

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

/**
 * _strcat : concatenates two strings
 * @ destination : the destination file 
 * @source : the source buffer
 * 
 * RETURN : destination buffer
*/

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
