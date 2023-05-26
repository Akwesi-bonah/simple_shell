#include "shell.h"
/**
 * create_process - create a fork process
 * @path: path to be freed
 * @cnt: number of command
 * @args: command passed
 * @name: name of execution
 * @line: commad line
 *
 * Return: count
 */

int create_process(char *path, char **args, char *line, int cnt, char *name)
{
	pid_t pid = 0, wpid;
	int status = 0;
	(void)wpid;
	pid = fork();

	if (pid < 0)
	{
		print_error(cnt, args[0], args[1], name);
		return (0);
	}
	else if (pid == 0)
	{
		if (execve(line, args, NULL) == -1)
		{
			print_error(cnt, args[0], args[1], name);
			free(path), free(line), free(args);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
