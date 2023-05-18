#include "shell.h"
/**
 * execute - find a special character and run
 * @cmd: command
 * @num_cmd: number of commands
 * @var: command
 * @er_msg: error message for the
 * @exe_name: name of the executable
 *
 * Return: 0
 */
int execute(char cmd[], int num_cmd, char *var, char *er_msg, char *exe_name)
{
	int len_cmd = _stelen(cmd);
	int flags = 0, xcode = 0;
	char *copy = NULL, *path;
	char **dir = NULL;

	copy = _calloc(len_cmd + 1, sizeof(char));
	path = get_path();
	dir = split_path(path);
	_strcopy(copy, cmd);

	if (flags == 0)
	{
		xcode = runcmd(cmd, dir, num_cmd, var, er_msg, exe_name);
	}
	else if (flags == 1)
	{
		xcode = scmd(copy, dir, num_cmd, var, er_msg, exe_name);
	}
	else if (flags == 3)
	{
		xcode = exe_d(copy, dir, num_cmd, var, er_msg, exe_name);
	}

	else if (flags == 4)
	{
		xcode = exe_c(copy, dir, num_cmd, var, er_msg, name);
	}
	free(path);
	free(copy);
	free(dir);

	return (xcode);
}
