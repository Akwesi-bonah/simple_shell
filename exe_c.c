#include "shell.h"
/**
 * exe_y - execute two commands
 * @cpy: command to execute
 * @dpt: directory path
 * @cnt: number of commands
 * @name: command name
 * @err: error message
 * @nm: executable name
 * Return: 0
 */
int exe_y(char cpy[], char *dpt[], int cnt, char *name, char *err, char *nm)
{
	int x = 0, a = 0, b = 0, ex = 0, status = 0;
	char *commandPath, *exec1, *exec2;
	char *commandParts[2], **arguments1 = NULL, **arguments2 = NULL;
	pid_t pid2, wpid;
	(void)wpid;

	_split(cpy, commandParts, "|");
	a = _strlen(commandParts[0]), b = _strlen(commandParts[1]);
	exec1 = _calloc(a, sizeof(char)), exec2 = _calloc(b, sizeof(char));
	_strcpy(exec1, commandParts[0]), _strcpy(exec2, commandParts[1]);
	x = (count(exec1, ' ')) + 2, arguments1 = _calloc(x, sizeof(char *));
	_split_space(arguments1, exec1), commandPath = check_path(dpt, arguments1[0]);
	if (commandPath == NULL)
		print_error(cnt, name, err, nm);
	else
	pid2 = fork();
	if (!pid2)
	{
		if (execve(commandPath, arguments1, environ) == -1)
		{print_error(cnt, name, err, nm);
			return (0);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid2 < 0)
	{print_error(cnt, name, err, nm);
		return (0);
	}
	else
	{
		do {wpid = waitpid(pid2, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	x = (count(exec2, ' ')) + 2, arguments2 = _calloc(x, sizeof(char *));
	_split_space(arguments2, exec2), commandPath = check_path(dpt, arguments2[0]);
	if (commandPath == NULL)
		print_error(cnt, name, err, nm);
	else
		ex = execve(commandPath, arguments2, environ);
	return (ex);
}
