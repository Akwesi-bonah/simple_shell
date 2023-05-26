#include "shell.h"
/**
 * main - This is program is a simple shell
 * @ac: number of argumnent
 * @av: argument passed
 * Return: 0 Always
 */
int main(int ac, char **av)
{
	char *user = NULL, *cmt = NULL;
	char **cmd = NULL;
	int xcode = 0, counter = 0;
	(void)ac;

	signal(SIGINT, shortcut_cmd);
	while (1)
	{
		counter++;
		write(STDIN_FILENO, "$ ", 2);
		user = read_cmd(), user = comments(user);
		if (user[0] == '\n')
		{
			free(user);
			continue;
		}

		cmt = _calloc(_strlen(user) + 1, sizeof(char));
		_strcpy(cmt, user);
		cmd = split_command(user);

		if (in(cmd, av, user, cmt, counter, xcode))
		{
			free(user), free(cmt), free(cmd);
			continue;
		}
		execute_cmd(cmd, user, cmt, counter, av[0]);
		free(user), free(cmt), free(cmd);
	}
	return (0);
}
