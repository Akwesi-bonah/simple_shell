#include "shell.h"
/**
 * _env - print enviroment variables
 * @cmd: command passed
 */

void _env(char **cmd)
{
	int i;
	char *str;

	if (cmd[1] != NULL)
		return;
	for (i = 0; (str = *environ) != NULL; i++)
	{
		write(STDIN_FILENO, str, strlen(str));
		write(STDIN_FILENO, "\n", 1);
		environ++;
	}
}
