#include "shell.h"
/**
 * run_cmd - forks the process
 * @p: path to be freed
 * @n: name of execution
 * @arg: command passed
 * @num: number of command
 * @ln: commnad line
 *
 * Return: count
 */

int run_cmd(char *p, char **arg, char *ln, int num, char *n)
{
	pid_t mypid = 0, wpid;
	int status = 0;
	(void)wpid;
	mypid = fork();

	if (mypid < 0)
	{
		print_err(num, arg[0], arg[1], n);
		return (0);
	}
	if (mypid == 0)
	{
		if (execute(ln, num, arg[0], arg[0], n) == -1)
		{
			print_err(num, arg[0], arg[1], n);
			free(p), free(ln), free(arg);
			return (0);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			wpid = waitpid(mypid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
