#include "shell.h"
/**
 * exit_shell - exit the shell.
 * @line: line of commands
 * @line2: line to free
 * @on: number of commands.
 * @arg: array of command and arguments.
 * @nm: name of the exe.
 * @ex: int value
 * Return: an integer.
**/

int exit_shell(char *line, char *line2, int on, char **arg, char *nm, int ex)
{
	int i, sts = ex;
	int digit = 1;

	if (arg[1] == NULL)
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
			break;
	}
	if (digit == 1)
		sts =  _atoi(arg[1]);
	else
		sts = 2;
	if (sts >= 0 && sts + 1 > 0 && sts != 2)
	{
		free(line), free(arg), exit(ex);
	}
	else
	{
		print_error(on, arg[0], arg[1], nm);
		return (sts);
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
