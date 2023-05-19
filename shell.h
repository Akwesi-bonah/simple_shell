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

int main(int ac, char **av);
int run_cmd(char **arg, char *pth, int cnt, char *vname, char *typ, char *nm);
int exit_shell(char *line, char *line2, int on, char **args, char *name, int ex);
void _env(char **args);
int create_process(char *path, char **args, char *line, int cnt, char *name);

char *read_cmd(void);
void *_calloc(unsigned int num, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *comments(char *line);
char *get_path(void);

char **split_path(char *env_path);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
void _itoa(int value, char *str, int base);
void rev_string(char *s);
char *_strchr(char *str, char c);
int space(char *cmd);
int count(char *args, char c);

int _isdigit(int c);
char *_strcpy(char *dest, char *src);
void print_error(int on, char *var_name, char *type, char *name);
int scmd(char c[], char *d[], int cnt, char *v, char *err, char *name);
char *check_path(char **directories, char *command);
char *combine_path(char *dir, char *command);
char **split_command(char *line);

void _split_space(char *argv[], char line2[]);
void _split(char line2[], char *scmd[], char c[]);
void shortcut_cmd(int num);
int runcmd(char *l, char *d[], int cnt, char *v, char *err, char *name);
int exe_y(char cpy[], char *dpt[], int cnt,char *name, char *err, char *ename);
int exe_d(char cpy[], char *path[], int cnt, char *cmd, char *err, char *name);
#endif

