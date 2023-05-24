#include "shell.h"
/**
 * change_dir - Change the current directory
 * @path: Path of the directory to change to
 * Return: 0 on success, -1 on failure
 */
int change_dir(const char *path)
{
	char *prev_dir = NULL;

	if (path == NULL)
		path = getenv("HOME");
	if (path == NULL)
	{
		fprintf(stderr, "cd: No home directory\n");
		return (-1);
	}
	if (strcmp(path, "-") == 0)
	{
		prev_dir = getenv("OLDPWD");
		if (prev_dir == NULL)
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
			return (-1);
		}
	}
	else
		prev_dir = getenv("PWD");
	if (prev_dir == NULL)
		prev_dir = "";
	if (chdir(path) != 0)
	{
		fprintf(stderr, "cd: No such file or directory: %s\n", path);
		return (-1);
	}
	if (setenv("PWD", path, 1) != 0)
	{
		fprintf(stderr, "cd: Failed to update PWD environment variable\n");
		return (-1);
	}
	if (setenv("OLDPWD", prev_dir, 1) != 0)
	{
		fprintf(stderr, "cd: Failed to update OLDPWD environment variable\n");
		return (-1);
	}
	return (0);
}
