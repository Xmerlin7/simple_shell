#include "main.h"
/**
* _strlen - Calculates and returns the length of a string.
* @str: The string to be calculated.
*
* Description: This function takes a string as input and calculates its length.
*
* Return: The number of characters of the given string.
*/
int _strlen(char *str)
{
int len;

for (len = 0; *(str + len); len++)
;
return (len + 1);
}
/**
* _strcpy - Copies the null-terminated string pointed to by src.
* @dest: Pointer to the destination where the source is to be copied.
* @src: Pointer to the source string to be copied.
*
* Description: This function copies the string pointed to by src
*
* Return: A pointer to the destination string dest.
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
* _strdup - Duplicates a string.
* @str: String to duplicate.
*
* Return: Pointer to the duplicate string, or NULL if memory allocation fails.
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
* _strcmp - Compares two strings.
* @str1: The first string.
* @str2: The second string.
*
* Return: 1 if the strings are equal, 0 otherwise.
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
* _strcat - Concatenates two strings.
* @destination: The first string.
* @source: The second string.
*
* Return: Pointer to the concatenated string, or NULL if an error occurs.
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
