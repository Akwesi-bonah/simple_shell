#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * main - This is program is a simple shell
 * @ac: number of argumnent
 * @av: argument passed
 *
 * Return 0 Always
 */
int main(int ac, char **av)
{
	(void)ac;
	char *user = NULL, *cmt = NULL;
	char **cmd = NULL;
	int xcode = 0, count = 0;

	while (1)
	{
		count++;
		write(STDIN_FILENO, "$ ", 2);
		user = read_cmd();
		user = comments(user);

		if (user[0] == '\n')
		{
			free(user);
			continue;
		}
		
		cmt = _calloc(_strlen(user) + 1, sizeof(char));
		_strcpy(cmt, user);
		cmd = split_command(user);

		if (!_strcmp("env", cmd[0]))
		{
			_env(cmd);
			free(user), free(cmt), free(cmd);
			continue;
		}
		if (!_strcmp("exit", cmd[0]))
		{
			xcode = exit_shell(user, cmt, count, cmd, av[0], xcode);
			if (xcode == 2)
			{
				free(user), free(cmt), free(cmd);
				continue;
			}
		}
		if (user[0] !=  '/')
		{
			create_process(user, cmd, cmt, count, av[0]);
		}
		else
		{
			run_cmd(cmd, user, count, cmd[0], cmd[1], av[0]);
		}
		free(user), free(cmt), free(cmd);
	}
	return (0);

}

