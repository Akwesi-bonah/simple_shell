#include "shell.h"
/**
 * check_path - check with stat in the directories in PATH with command
 * @directories: pointer array of directories in PATH
 * @command: pointer to command name
 * Return: pointer if found, NULL not found
 */
char *check_path(char **directories, char *command)
{
	struct stat file_metadata;
	char *full_path;
	int i = 0;

	while (directories[i])
	{
		full_path = combine_path(directories[i], command);
		if (stat(full_path, &file_metadata) == 0)
			return (full_path);
		i++;
	}
	return (NULL);
}

/**
 * combine_path - Concatenates a directory path and a command
 * @dir: Pointer to a string that represents the directory path
 * @command: Pointer to a string that represents the command
 * Return: Pointer to a string that represents the combined path
 */
char *combine_path(char *dir, char *command)
{
	int dir_len, command_len, len, i = 0, j = 0;
	char *path_command;

	dir_len = _strlen(dir);
	command_len = _strlen(command);

	len = dir_len + command_len;
	path_command = calloc(len + 2, sizeof(char));
	if (path_command == NULL)
	{
		write(1, "Error: malloc combine_path\n", 23);
		return (NULL);
	}

	while (dir[i])
	{
		path_command[i] = dir[i];
		i++;
	}
	path_command[i] = '/';
	i++;
	while (command[i])
	{
		path_command[i] = command[j];
		j++;
		i++;
	}
	path_command[i] = '\0';
	return (path_command);
}
