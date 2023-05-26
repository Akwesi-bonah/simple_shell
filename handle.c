#include "shell.h"
/**
 * handle_cmd - Handle the given command and its arguments
 * @cmd: The command and its arguments as an array of strings.
 * @input: command
 * @argv: The program's command-line arguments.
 * @num: The counter indicating the command's position.
 * @pr_status: A pointer to the previous command's exit status.
 * Return: If the command is "exit"
 */
int handle_cmd(char **cmd, char *input, char **argv, int num, int *pr_status)
{
	int status;
	char **next_cmd;

	if (strcmp(cmd[0], "exit") == 0)
	{
		exit_bul(cmd, input, argv, num);
		return (0);
	}
	else if (strcmp(cmd[0], "&&") == 0)
	{
		if (*pr_status == 0)
		{
			next_cmd = parse_cmd(cmd[1]);
			status = check_cmd(next_cmd, input, num, argv);
			*pr_status = status;
		}
	}
	else if (strcmp(cmd[0], "||") == 0)
	{
		if (*pr_status != 0)
		{
			next_cmd = parse_cmd(cmd[1]);
			status = check_cmd(next_cmd, input, num, argv);
			free_all(next_cmd, NULL);
			*pr_status = status;
		}
	}
	else
	{
		next_cmd = parse_cmd(cmd[0]);
		status = check_cmd(cmd, input, num, argv);
		*pr_status = status;
	}
	*pr_status = status;
	return (1);
}
