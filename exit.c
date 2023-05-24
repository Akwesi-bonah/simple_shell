#include "shell.h"
/**
 * exit_shell - exit the shell.
 * @line: line of commands
 * @line2: line to free
 * @on: number of commands.
 * @arg: array of command and arguments.
 * @name: name of the exe.
 * @ex: int value
 * Return: an integer.
**/

int exit_shell(char *line, char *line2, int on, char **arg, char *name, int ex)
{
	int i, sts;
	int digit = 1;

	if (args[1] == NULL)
	{
		free(line);
		free(line2);
		free(arg);
		exit(EXIT_SUCCESS);
	}
	for (i = 0; arg[1][i] != '\0'; i++)
	{
		digit = _isdigit(arg[1][i]);
		if (digit == 0)
		{
			break;
		}
	}
	sts = digit ? _atoi(arg[1]) : 2;

	if (sts < 0 || sts + 1 > 0 && sts != 2)
	{
		print_error(on, arg[0], arg[1], name);
		return (2);
	}

	free(line);
	free(arg);
	free(ex);

	if (args[1] == NULL)
	{
		free(line);
		free(line2);
		free(arg);
		exit(EXIT_SUCCESS);
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
