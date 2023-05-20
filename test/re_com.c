#include "shell.h"
/**
 * re_com - remove comment from from command line
 * @arg: line
 *
 * Return: line without commentes
 */

char *re_com(char *arg)
{
	int i = 0, j = 0;
	char *cmp = " \t\r\a";
	char ax;

	while (cmp[j] != '\0')
	{
		if (arg[0] == cmp[j])
		{
			while (arg[i] != '\0')
			{
				ax = arg[i + 1];
				arg[i] = ax;
				i++;
			}
		}
		j++;
	}
	for (i = 0; arg[0] != '\0'; i++)
	{
		if (arg[0] == '#')
		{
			arg[0] = '\0';
			break;
		}
	}
	return (arg);
}
