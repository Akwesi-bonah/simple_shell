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
	char *user_input = NULL;
	char *comment = NULL;
	char **command = NULL;
	int exit_code = 0;
	int command_number = 0;

	while (1)
	{
		command_number++;
		write(STDOUT_FILENO, "$ ", 2);
		user_input = read_command();
		comment = comments(user_input);

		if (comment[0] == '\n');
		{
			free(user_input);
			continue;
		}

		command = split_command(comment);
		if (comment[0] != '/')
		{
			create_process(user_input, command, comment, command_number);
		}else
			run_command(command, user_input, command_number, command[0], command[1], NULL);
		if (!_strcmp(command[0], "exist"))
		{
			exit_code = exit_shell(user_input, comment, command_number, NULL, "shell");
			if (exit_code == 2)
			{
				free(user_input);
				free(comment);
				free(command);
				continue;
			}
		}
		if (!_strcmp(command[0], "env"))
		{
			_env(command);
			free(user_input);
			free(comment);
			free(command);
			continue;
		}
		free(user_input);
		free(command);
		free(comment);
	}
	return (0);
}

