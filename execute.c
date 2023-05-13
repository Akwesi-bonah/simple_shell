#include "shell.h"
/**
 * run_command - function that runs command passed
 * @args: argument passed
 * @path: on
 */


int run_command(char **args, char *path, int on,char *var_name, char *type, char *name)
{
	pid_t pid, wpid;
	int status;
	char exe_path[128] = "/bin";
	char *aux_path = "/b";
	(void)wpid;

	if (path[0] == aux_path[0] && path[1] == aux_path[1])
	{
		strcpy(exe_path, path);
	}else{
		strcat(exe_path, "/");
		strcat(exe_path, path);
	}
	pid = fork();

	if (pid < 0)
	{
		print_error(on, var_name, type, name);
		return (0);
	}

	if (pid == 0)
	{
		if (execve(exe_path, args, NULL) == -1)
		{
			print_error(on, var_name, type, name);
			exit(EXIT_FAILURE);
		}
	}else{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}


