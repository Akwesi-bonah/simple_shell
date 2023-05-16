#ifndef shell_H
#define shell_H

#define PATH_MAX 4096
#include <limits.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <fcntl.h>

extern char **environ;

char *readc(void);
int _strlen(char *s);
int execute(char line2[], int cont, char *v, char *t, char *n);
void _env(char **args);
int _strcmp(char *s1, char *s2);
int _str(char *s);

char **split_command(char *line);
char *comments(char *line);
int run_command(char **args, char *path, int on,char *var_name, char *type, char *name);
void print_error(int on, char *val_name, char *type, char *name);
int create_process(char *path, char **args, char *name, int on);
int exit_shell(char *line, char *line2, int on, char **args, char *name);
int _isdigit(int c);
int _atoi(char *s);

void _itoa(int value, char *str, int base);
char *read_command(void);
void rev_string(char *s);

char **split_path(char *env_path);
char *getpath(void);
char *check_path(char **directories, char *command);
char *combine_path(char *dir, char *command);
char *_strchr(char *s, char c);
int space(char *cmd);
int execute(char *command, int num_cmd, char *var, char *er_msg, char *exe_name)
void *_calloc(unsigned int num, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
#endif

