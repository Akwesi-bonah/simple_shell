#include "shell.h"
/**
 * execute - find a special character and run
 * @command: command
 * @num_cmd: number of commands
 * @var: command
 * @er_msg: error message for the
 * @exe_name: name of the executable
 *
 * Return: 0
 */

int execute(char *command, int num_cmd, char *var, char *er_msg, char *exe_name)
{
	int len_cmd = _strlen(command);
	int flags = 0;
	int exit_code = 0;
	char *copy = NULL;
	char *path = NULL;
	char *dir = NULL;

	copy = _calloc(len_cmd + 1, sizeof(char));
	path = get_path();
	dir = split_path(path);
	flags = get_flags(command);
	_strcpy(copy, command);

	if (flags == 0)
	{
		exit_code = run(command, dir, num_cmd, var, er_msg, exe_name);
	} else if (flags == 1)
	{
		scolon(copy, dir, num_cmd, var, er_msg, exe_name);
	} else if (flags == 2)
	{
		exit_code = OO(copy, dir, num_cmd, var, er_msg, exe_name);
	} else if (flags == 3)
	{
		exit_code = YY(copy, dir, dir, num_cmd, var, er_msg, exe_name);
	}

	free(path);
	free(copy);
	free(dir);

	return (exit_code);
}
/**
 * _strchr - locate string character
 * @s: string to search from
 * @c: charcter to find
 *
 * Return: c if found else NUll
 */
char *_strchr(char *s, char c)
{
	int x;

	while (1)
	{
		x = *s++;
		if (x == c)
		{
			return (s - 1);
		}

		if (x == 0)
		{
			return (NULL);
		}
	}
}
/**
 * space - search spaces in the command
 * @cmd: command
 * Return: 1 if found, else 0
 */
int space(char *cmd)
{
	if (_strchr(cmd, ' ') != NULL)
	{
		return (1);
	}
	return (0);
}
