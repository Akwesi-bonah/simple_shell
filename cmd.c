#include "shell.h"
/**
 * runcmd - execute command
 * @l: command
 * @d: directories the path
 * @cnt: number of commands
 * @v: command
 * @err: error of the command
 * @name: name of the exe
 * Return: 0
 */
int runcmd(char *l, char *d[], int cnt, char *v, char *err, char *name)
{
	int x = 0, ex = 0;
	char *dpcmd;
	char **args = NULL;

	x = (count(l, ' ')) + 2;
	args = _calloc(x, sizeof(char *));
	_split_space(args, l);
	dpcmd = check_path(d, args[0]);
	if (dpcmd == NULL)
	{
		free(dpcmd);
		print_error(cnt, v, err, name);
	}
	else
		ex = execve(dpcmd, args, environ);
	free(args);
	return (ex);
}
