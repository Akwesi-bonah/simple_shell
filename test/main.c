#include "shell.h"
/**
 * main - mini bash shell
 * @ac: number of argument passed
 * @av: argument passed
 *
 * Return: 0 (success) Always
 */

int main(int ac, char **av)
{
	char *user = NULL, *copy = NULL;
	char **cmet = NULL;
	int xcode = 0, count = 0;
	(void)ac;

	signal(SIGINT, shortcut);
	while (1)
	{
		count++;
		write(STDIN_FILENO, "$ ", 2);
		user = read_cmd(), user = re_com(user);
		if (user[0] == '\n')
		{
			free(user);
			continue;
		}
		user = _calloc(strlen(user) + 1, sizeof(char));
		strcpy(copy, user), cmet = split_cmd(user);
		if (!strcmp("env", cmet[0]))
		{
			_env(cmet);
			free(user), free(copy), free(cmet);
			continue;
		}
		if (!strcmp("exit", cmet[0]))
		{
			xcode = exit_code(user, copy, count, cmet, av[0], xcode);
			if (xcode == 2)
			{
				free(user), free(copy), free(cmet);
				continue;
			}
		}
		if (user[0] != '/')
			run_cmd(user, cmet, copy, count, av[0]);
		else
			execute_cmd(cmet, user, count, cmet[0], cmet[1], av[0]);
		free(user), free(user), free(copy);
	}
	return (0);
}
