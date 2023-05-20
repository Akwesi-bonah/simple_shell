#ifndef SHELL_H
#define SHELL_H

#define PATH_MAX 40
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <errno.h>

extern char **environ;

int main(int ac, char **av);
void _env(char **cmd);
int run_cmd(char *p, char **arg, char *ln, int num, char *n);
void *_calloc(unsigned int num, unsigned int size);
char *re_com(char *arg);
void print_err(int num, char *cmd, char *type, char *name);
int execute_cmd(char **args, char *ln, int num, char *cmd, char *err , char *nm);
char *read_cmd(void);
int _isdigit(int c);
void shortcut(int num);
char **split_cmd(char *line);
int exit_code(char *line, char *fre, int num, char **cmd, char *name, int x);

#endif
