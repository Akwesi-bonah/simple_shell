#include "shell.h"
/**
 * _env - function that print enviroment varibles
 * @args: command passed
 */

void _env(char **args)
{
	int i;
	char *str;

	if (args[1] != NULL)
	{
		return;
	}

	for (i = 0; (str = *environ) != NULL; i++)
	{
		write(STDIN_FILENO, str, strlen(str));
		write(STDIN_FILENO, "\n", 1);
		environ++;
	}
}
