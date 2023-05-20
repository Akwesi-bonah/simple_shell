#include "shell.h"
/**
 * execute_cmd - function that runs a command passed
 * @num: number of command
 * @cmd: commnad
 * @nm: name of execuation
 * @args: argument passed
 * @err: error of the command
 * @ln: command line
 *
 * Return: count
 */

int execute_cmd(char **args, char *ln, int num, char *cmd, char *err , char *nm)
{
	pid_t pid;
	int status;
	char us[128] = "/bin";

	if (strncmp(ln, "/b", 2) == 0)
		strcpy(us, ln);
	else
		snprintf(us, sizeof(us), "/bin/%s", ln);
	pid = fork();

	if (!pid == 0)
	{
		if (execve(us, args, NULL) == -1)
		{
			print_err(num, cmd, err, nm);
			return (0);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		print_err(num, cmd, err, nm);
		return (0);
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
	}

	return (1);
}
