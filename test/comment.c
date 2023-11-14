#include "shell.h"

/**
 * comments - remove comments form the commasnd line
 * @line: command line argument
 *
 * Return: command without comments
 */

char *comments(char *line)
{
	int i, j = 0;
	char *compare = " \t\r\a";
	char aux;

	while (compare[j] != '\0')
	{
		if (line[0] == compare[j])
		{
			for (i = 0; line[i] != '\0'; i++)
			{
				aux = line[i + 1];
				line[i] = aux;
			}
		}
		j++;
	}

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == '#')
		{
			line[i] = '\0';
			break;
		}
	}
	return (line);
}
