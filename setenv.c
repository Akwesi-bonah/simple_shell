#include "shell.h"
/**
 * setenv_builtin - This function sets the environment variable
 * @cmd: cmd - The command line arguments
 * @er: int value
 * Return: 0 on success, -1 on error
 */
int setenv_builtin(char **cmd, int er)
{
	if (cmd[1] == NULL || cmd[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}
	if (setenv(cmd[1], cmd[2], 1) == -1)
	{
		fprintf(stderr, "Failed to set variable: %s\n", cmd[1]);
		return (-1);
	}
	er = 0;
	return (er);
}
/**
 * unsetenv_builtin - This function unsets the environment variable
 * @cmd: cmd - The command line arguments
 * @er: int value
 * Return: 0 on success, -1 on error
 */
int unsetenv_builtin(char **cmd, int er)
{
	if (cmd[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return (-1);
	}
	if (unsetenv(cmd[1]) == -1)
	{
		fprintf(stderr, "Failed to unset variable: %s\n", cmd[1]);
		return (-1);
	}
	er = 0;
	return (er);
}
