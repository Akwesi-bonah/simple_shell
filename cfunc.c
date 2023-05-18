#include "shell.h"
/**
 * count - count number of command
 * @args: command passed
 * @c: delimeter
 *
 * Return: count
 */

int count(char *args, char c)
{
	int j = 0;
	int k = 0;

	while (args[j])
	{
		if (args[j] == c)
		{
			k++;
		}
		j++;
	}
	return (k);
}

/**
 * space - search spaces in the commad
 * @cmd: command passed
 *
 * Return: 1 if found else 0
 */

int space(char *cmd)
{
	if (_strchr(cmd, ' ') != NULL)
		return (1);

	return (0);
}

/**
 * _strchr - locate string character
 * @str: string to find
 * @c: character to find
 *
 * Return: c if found else NULL
 */
char *_strchr(char *str, char c)
{
	int i;

	while (1)
	{
		i = *str++;
		if (i == c)
			return (str - 1);
		if (i == 0)
			return (NULL);
	}
}
