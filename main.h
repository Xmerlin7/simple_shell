#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define DELIM " \t\n"
extern char **environ;

char *read_line(void);
char **_tknizer(char *line);
void free2D(char **arr);
int exec_command(char **command, char **argv, int idx);
char *_getenv(char *name);
char *_getpath(char *cmd);

void bltn_handler(char **cmd, char **argv, int *sta, int idx);
int is_bltn(char *cmd);
void print_env(char **cmd, int *sta);
void exit_shell(char **cmd, char **argv, int *sta, int idx);

char *_strcat(char *destination, const char *source);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strlen(char *str);
int _strcmp(char *str1, char *str2);

ssize_t _getline(char **line, size_t length, int position);
void _env(void);
void print_error(char *prog, char *cmd, int ctr);

int str_to_int(char *str);
int is_positive(char *str);
char *int_to_str(int n);
void rev_str(char *str, int len);
int print_string(char *str);
int _putchar(char *c);

#endif /* MAIN_H */
