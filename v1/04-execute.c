#include "main.h"

/**
 * exec func : forks a child process to exec with arg
 * execve : replace the child process with command
 * @command : array represents command and its arg
 * @argv : array represents arg pass to the program
 * @idx : index of command in the input
 *
 * RETURN : exec command , and if failure returns 127
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
