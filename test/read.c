#include "shell.h"
/**
 * read_cmd read command
 * Return: string of commands
 */

char *read_cmd(void)
{
	char *cmd = NULL;
	size_t bf = 0;
	size_t i = 0;

	i = getline (&cmd, &bf, stdin);
	if (i == -1)
		exit(0);
	return (cmd);
}
