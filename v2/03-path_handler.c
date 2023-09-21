#include "main.h"
/**
* _getenv - Retrieves the value of an environment variable.
* @name: The name of the environment variable to search for.
*
* Description: This function takes the name of an environment variable as input
* and searches for it.
*
* Return: A pointer to a string  of the environment variable on success,
* or NULL if  an error occurs.
*/
char *_getenv(char *name)
{
char *tmp = NULL;
char *env;
char *key = NULL;
char *value;
int i;

for (i = 0; environ[i]; i++)
{
tmp = _strdup(environ[i]);
key = strtok(tmp, "=");
if (_strcmp(key, name) == 0)
{
value = strtok(NULL, "\n");
env = _strdup(value);
free(tmp);
return (env);
}
free(tmp), tmp = NULL;
}

return (NULL);
}
/**
* _getpath - Determines the full path of a command.
* @command: A pointer to a string representing the command name.
*
* Description: This function takes a command name and determines its full path.
*
* Return: A pointer to a string of the full path on success,
* or NULL if an error occurs.
*/
char *_getpath(char *command) /*add to main.h*/
{
char *_path, *full_path, *tmp;
int i;
struct stat st;
/*when we in the PATH*/
for (i = 0; command[i]; i++)
{
if (command[i] == '/')
{
if (stat(command, &st) == 0) /*PATH exists*/
return (_strdup(command));
return (NULL);
}
}
/*PATH unset*/
_path = _getenv("PATH");
if (!_path)
return (NULL);

/*handles the PATH*/
tmp = strtok(_path, ":");
while (tmp)
{
/*size = len(tmp) + len(command) +2 ('/' and '\0')*/
full_path = malloc(_strlen(tmp) + _strlen(command) + 2);
if (full_path)
{
_strcpy(full_path, tmp);
_strcat(full_path, "/");
_strcat(full_path, command);
if (stat(full_path, &st) == 0)
{
free(_path);
return (full_path);
}
free(full_path), full_path = NULL;
tmp = strtok(NULL, ":");
}
}
free(_path);
return (NULL);
}
