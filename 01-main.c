#include "main.h"

/**
* main - entry level function
*@arc : number of passed arguments
*@argv : arguments
*
* return : The return value of the last executed command
*/

int main(int arc, char **argv)
{
char *line = NULL;
char **command;
int sta;
int idx = 0;
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
if (!command) /* handels the space*/
{
free2D(command);
continue;
}
if (is_bltn(command[0]))

bltn_handler(command, argv, &sta, idx);
else
sta = exec_command(command, argv, idx);
}
return (0);
}
