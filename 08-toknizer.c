#include "main.h"

/**
* **_tknizer - splits a string into words
* repeat delimiters are ignored
* @line : the string to be tokenized
* RETUERN : the array of tokens , or NULL on failure
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
