#include "shell.h"
/**
 * run_cmd - execute command
 * @cnt: number of commands
 * @vname: command.
 * @typ: error of the command
 * @nm: name of the exe
 * @arg: aguments of the command
 * @pth: line of command
 * Return: count
**/
int run_cmd(char **arg, char *pth, int cnt, char *vname, char *typ, char *nm)
{
	pid_t pid, wpid;
	int status;
	char exe_path[128] = "/bin";
	char *aux_path = "/b";
	(void)wpid;

	if (pth[0] == aux_path[0] && pth[1] == aux_path[1])
	{
		strcpy(exe_path, pth);
	}
	else
	{
		strcat(exe_path, "/");
		strcat(exe_path, pth);
	}
	pid = fork();

	if (pid < 0)
	{
		print_error(cnt, vname, typ, nm);
		return (0);
	}

	if (pid == 0)
	{
		if (execve(exe_path, arg, NULL) == -1)
		{
			print_error(cnt, vname, typ, nm);
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


