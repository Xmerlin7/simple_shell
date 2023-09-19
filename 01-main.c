#include "main.h"
char *line = NULL;
char **command;
int ss;
int i = 0, idx = 0;
int main(int arc, char **argv)
{
    (void)arc;

    while (1)
    {
        line = read_line();
        if (line == NULL) /*handle EOF ctr + D*/
        {
            if (isatty(STDERR_FILENO))
                write(STDOUT_FILENO, "\n", 1);

            return (0);
        }
        idx++;
        command = _tknizer(line);
        if (command == NULL) /* handels the space*/
        {
            free2D(command);
            continue;
        }
        else if (_strcmp(command[0], "exit") == 0)
            break;
        else if (_strcmp(command[0], "env") == 0)
            print_env();
        ss = exec_command(command, argv, idx);
    }
    return (0);
}