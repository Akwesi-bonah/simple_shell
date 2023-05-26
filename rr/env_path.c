#include "shell.h"
/**
 * get_path - Gets the Path environment
 *
 * Return: path pointer
 */

char *get_path(void)
{
	unsigned int a, b, c;
	char *str, **enp = environ;

	c = 0;
	for (a = 0; enp[a]; a++)
	{
		if (enp[a][0] == 'P' && enp[a][3] == 'H' && enp[a][4] == '=')
		{
			str = _calloc(PATH_MAX, sizeof(char));
			if (str == NULL)
			{
				write(1, "Error: failed malloc getpath\n", 27);
				return (NULL);
			}
			for (b = 5; enp[a][b]; b++)
			{
				str[c] = enp[a][b];
				c++;
			}

			str[c] = '\0';

			return (str);
		}
	}

	return (0);
}

/**
 * split_path - function that splits path each ':'
 * @env_path: Pointer value of the PATH
 *
 * Return: each directories of the pointer
 */

char **split_path(char *env_path)
{
	char **dir;
	char *token;
	int i = 0;

	dir = _calloc(PATH_MAX, sizeof(char *));
	if (dir == NULL)
	{
		write(1, "Error: failed malloc split_path\n", 31);
		return (NULL);
	}
	token = strtok(env_path, ":");
	while (token)
	{
		dir[i] = token;
		token = strtok(NULL, ":");
		i++;
	}
	dir[i] = NULL;
	return (dir);
}
