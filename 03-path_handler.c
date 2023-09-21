#include "main.h"

/**
* _getenv - takes pointer char to array to represent env
* @name : search for env variable
* RETURN : if success value of name , if failure return NULL
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
* _getpath : takes pointer char to array represents the command name
* @command : 
* RETURN : if success full_path , if failur return NULL
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
