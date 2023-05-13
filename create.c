#include "shell.h"

int create_process(char *path, char **args, char *name, int on)
{
	pid_t pid = 0, wpid;
	int status = 0;
	(void)wpid;

	pid = fork();

	if (pid < 0)
	{
		print_error(on, args[0], args[1], name);
		return (0);
	}

	if (pid == 0)
	{
		if (execve(path, args, NULL) == -1)
		{
			print_error(on, args[0], args[1], name);
			exit(EXIT_FAILURE);
		}
	}
	else {
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));

	}

	return (1);
}
