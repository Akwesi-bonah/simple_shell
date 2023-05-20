#include "shell.h"
/**
 * exit_code = exit the shell
 * @line: line of command
 * @fre: line to be freed
 * @num: number of command
 * @cmd: array of command
 * @name: name of execution
 *
 * Return: count
 */

int exit_code(char *line, char *fre, int num, char **cmd, char *name, int x)
{
	int i, w = 1;
	if (cmd[1] == NULL)
	{
		free(line),free(fre), free(cmd);
	}

	for (i = 0; cmd[1][i] != '\0'; i++)
	{
		if (!_isdigit(cmd[1][i]))
			break;
		x = atoi(cmd[1]);
	}
	if (x >= 0 && x + 1 > 0 && x != 2)
	{
		free(line), free(cmd);
		exit(x);
	}
	else
	{
		print_err(num, cmd[0], cmd[1], name);
		return (x);
	}
}
/**
 * _isdigit - check if a character is between 0 - 9
 *
 * @c: character to check
 * Return: 1 if  then character is  a number else 0
 */
int _isdigit(int c)
{
        return (c >= '0' && c <= '9');
}
