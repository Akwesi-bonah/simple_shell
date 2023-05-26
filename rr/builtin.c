#include "shell.h"
/**
 * in - Handle the execution of builtin commands
 * @cmd: Command and arguments array
 * @av: Arguments passed to the program
 * @user: User input string
 * @cmt: User input string without comments
 * @counter: Command counter
 * @xcode: Exit code
 * Return: 1 if command is a builtin and handled, 0 otherwise
 */
int in(char **cmd, char **av, char *user, char *cmt, int counter, int xcode)
{
	if (cmd[0] == NULL)
		return (0);
	if (strcmp(cmd[0], "env") == 0)
	{ _env(cmd);
		return (1);
	}
	else if (strcmp(cmd[0], "exit") == 0)
	{
		xcode = exit_shell(user, cmt, counter, cmd, av[0], xcode);
		if (xcode == 2)
			return (1);
	}
	else if (strcmp(cmd[0], "setenv") == 0)
	{
		if (cmd[1] != NULL && cmd[2] != NULL)
			set_env(cmd[1], cmd[2]);
		else
			printf("Usage: setenv <variable> <value>\n");
		return (1);
	}
	else if (strcmp(cmd[0], "unsetenv") == 0)
	{
		if (cmd[1] != NULL)
			unset_env(cmd[1]);
		else
			printf("Usage: unsetenv <variable>\n");
		return (1);
	}
	else if (strcmp(cmd[0], "cd") == 0)
	{
		if (change_dir(cmd[1]) != 0)
		{
			fprintf(stderr, "cd: Failed to change directory\n");
			return (1);
		}
	}
	return (0);
}
