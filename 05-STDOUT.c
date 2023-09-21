#include "main.h"

/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1 , otherwise error
*/

int _putchar(char *c)
{
return (write(1, c, 1));
}
/**
*print_string - print the string to output
*@str :  a pointer to the program's character
*return :1 on success , otherwise error
*/
int print_string(char *str)
{
int i;

for (i = 0; str[i]; i++)
_putchar((str + i));

return (i);
}
