#include "shell.h"
/**
 * exe_d - execute two commands
 * @cpy: command complete
 * @path: directory path
 * @cnt: number of commands.
 * @cmd: command.
 * @err: error of the command.
 * @name: name of the exe.
 * Return: 0
 */
int exe_d(char cpy[], char *path[], int cnt, char *cmd, char *err, char *name)
{
	int x = 0, a = 0, b = 0, ex = 0, status = 0;
	char *cmdPath, *e1, *e2, *parts[2], **args1 = NULL, **args2 = NULL;
	pid_t pid2, wpid;
	(void)wpid;

	_split(cpy, parts, "|");
	a = _strlen(parts[0]), b = _strlen(parts[1]);
	e1 = _calloc(a, sizeof(char)), e2 = _calloc(b, sizeof(char));
	_strcpy(e1, parts[0]), _strcpy(e2, parts[1]);
	x = (count(e1, ' ')) + 2, args1 = _calloc(x, sizeof(char *));
	_split_space(args1, e1), cmdPath = check_path(path, args1[0]);
	if (cmdPath == NULL)
		print_error(cnt, cmd, err, name);
	else
	pid2 = fork();
	if (!pid2)
	{
		if (execve(cmdPath, args1, environ) == -1)
		{print_error(cnt, cmd, err, name);
			return (0);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid2 < 0)
	{print_error(cnt, cmd, err, name);
		return (0);
	}
	else
	{
		do {wpid = waitpid(pid2, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	x = (count(e2, ' ')) + 2, args2 = _calloc(x, sizeof(char *));
	_split_space(args2, e2), cmdPath = check_path(path, args2[0]);
	if (cmdPath == NULL)
		print_error(cnt, cmd, err, name);
	else
		ex = execve(cmdPath, args2, environ);
	return (ex);
}
