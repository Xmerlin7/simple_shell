#include "main.h"

/**
* _strlen - return the length of a string
* @str : the string wants to check its length
*len - length of char
* RETURN : number of characters
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
* @dest : Pointer to the destination of copied string.
* @src: Pointer to the src of the source string.
*
* RETURN : Pointer to dest.
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
* RETURN : new char pointer to the new string
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
* RETURN : 1 success case, 0 error case
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
* @destination : first string
* @source : secound string
*
* RETURN :  the combination of first and second string
* NULL on error case
*/

char *_strcat(char *destination, const char *source)
{
char *ptr = destination + strlen(destination);

while (*source != '\0')
{
*ptr++ = *source++;
}
*ptr = '\0';

return (destination);
}
