#include "main.h"

int is_bltn(char *cmd)
{
    char *bltn[] = {
        "exit", "env", "setenv", "cd", NULL};
    int i;
    for (i = 0; bltn[i]; i++)
    {
        if (_strcmp(cmd, bltn[i]) == 0)
            return (1);
    }
    return (0);
}
void bltn_handler(char **cmd, char **argv, int *sta, int idx)
{
    (void)argv;
    (void)idx;

    if (_strcmp(cmd[0], "exit") == 0)
        exit_shell(cmd, argv, sta, idx);
    else if (_strcmp(cmd[0], "env") == 0)
        print_env(cmd, sta);
}
void exit_shell(char **cmd, char **argv, int *sta, int idx)
{
    char *index;
    char err[] = ": exit Illegal number: ";
    int EXIT_VALUE = (*sta);

    if (cmd[1])
    {
        if (is_positive(cmd[1]))
        {
            EXIT_VALUE = str_to_int(cmd[1]);
        }
        else
        {
            index = int_to_str(idx);
            write(STDERR_FILENO, argv[0], _strlen(argv[0]));
            write(STDERR_FILENO, ": ", 2);
            write(STDERR_FILENO, index, _strlen(index));
            write(STDERR_FILENO, err, _strlen(err));
            write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
            write(STDERR_FILENO, "\n", 1);
            free(index);
            free2D(cmd);
            (*sta) = 2; /* if string*/
            return;
        }
    }
    free2D(cmd);
    exit(EXIT_VALUE);
}

void print_env(char **cmd, int *sta)
{
    int i;

    for (i = 0; environ[i]; i++)
    {
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
    free2D(cmd);
    *sta = 0;
}
