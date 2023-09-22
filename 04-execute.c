#include "main.h"
/**
* exec_command - Executes a command.
* @command: A pointer to an array of strings representing arguments.
* @argv: A pointer to an array of strings represent the arguments
* passed to the program.
* @idx: The index of the command counter.
*
* Description: This function forks a child process to execute the command.
*
* Return: The exit status on success, or 127 if an error occurs.
*/
int exec_command(char **command, char **argv, int idx)
{
pid_t child;
int status;
char *full_path = NULL;

full_path = _getpath(command[0]);
if (!full_path)
{
print_error(argv[0], command[0], idx);
free2D(command);
return (127);
}
child = fork();
if (child == 0)
{
if (execve(full_path, command, environ) == -1)
{
free(full_path), full_path = NULL;
free2D(command);
}
}
else
{
waitpid(child, &status, 0);
free2D(command);
free(full_path), full_path = NULL;
}
return (WEXITSTATUS(status));
}
