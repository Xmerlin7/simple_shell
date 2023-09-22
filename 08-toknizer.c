#include "main.h"
/**
* _tknizer - Splits a string into words.
* @line: The string to be tokenized.
*
* Description: This function takes a string and splits it into words,
*
* Return: Pointer to the array of tokens on success, or NULL on failure.
*/
char **_tknizer(char *line)
{
char **command = NULL;
char *token = NULL;
char *tmp = NULL;
int ctr = 0, i = 0;

if (!line)
return (NULL);
tmp = _strdup(line);

token = strtok(tmp, DELIM);
if (token == NULL)
{
free(tmp), tmp = NULL;
free(line), line = NULL;
return (NULL);
}
while (token)
{
token = strtok(NULL, DELIM);
ctr++;
}
free(tmp), tmp = NULL;

command = malloc(sizeof(char *) * (ctr + 1));
if (!command)
{
free(line), line = NULL;
return (NULL);
}
token = strtok(line, DELIM);
while (token)
{
command[i] = _strdup(token);
token = strtok(NULL, DELIM);
i++;
}
free(line), line = NULL;
command[i] = '\0';

return (command);
}
