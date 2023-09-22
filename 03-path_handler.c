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
char *temp_path = NULL;
char *env;
char *path_key = NULL;
char *path_value;
int i;

for (i = 0; environ[i]; i++)
{
temp_path = _strdup(environ[i]);
path_key = strtok(temp_path, "=");
if (_strcmp(path_key, name) == 0)
{
path_value = strtok(NULL, "\n");
env = _strdup(path_value);
free(temp_path);
return (env);
}
free(temp_path), temp_path = NULL;
}

return (NULL);
}
/**
* _getpath - Determines the full path of a command.
* @path_cmd: A pointer to a string representing the command name.
*
* Description: This function takes a command name and determines its full path.
*
* Return: A pointer to a string of the full path on success,
* or NULL if an error occurs.
*/
char *_getpath(char *path_cmd) /*add to main.h*/
{
char *_path, *full_path, *temp_path;
int i;
struct stat st;
/*when we in the PATH*/
for (i = 0; path_cmd[i]; i++)
{
if (path_cmd[i] == '/')
{
if (stat(path_cmd, &st) == 0) /*PATH exists*/
return (_strdup(path_cmd));
return (NULL);
}
}
    /*PATH unset*/
_path = _getenv("PATH");
if (!_path)
return (NULL);

/*handles the PATH*/
temp_path = strtok(_path, ":");
while (temp_path)
{
/*size = +2 for  ('/' and '\0')*/
full_path = malloc(_strlen(temp_path) + _strlen(path_cmd) + 2);
if (full_path)
{
_strcpy(full_path, temp_path);
_strcat(full_path, "/");
_strcat(full_path, path_cmd);
if (stat(full_path, &st) == 0)
{
free(_path);
return (full_path);
}
free(full_path), full_path = NULL;
temp_path = strtok(NULL, ":");
}
}
free(_path);
return (NULL);
}
