#include "shell.h"
/**
 * read_cmd - read line command
 * Return: string line with line break
 */

char *read_cmd(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t i = 0;

	i = getline(&line, &bufsize, stdin);

	if (i == -1)
		return (NULL);

	return (line);
}
