#include "shell.h"

/**
 * main - Simple Shell (Hsh)
 * @argc: Argument Count
 * @argv:Argument Value
 * Return: Exit Value By Status
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, *token, *rest, **cmd;
	int counter = 0, status = 1, st = 0;

	if (argv[1] != NULL)
		read_file(argv[1], argv);
	signal(SIGINT, signal_to_handel);

	while (status)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = _getline();
		if (input[0] == '\0')
		{
			free(input);
			continue;
		}
		rest = input;
		while ((token = strtok_r(rest, ";", &rest)))
		{
			if (token[0] == '\0')
				continue;
			history(token);
			cmd = parse_cmd(token);
			if (handle_builtin(cmd, st) == -1)
			{
				status = handle_cmd(cmd, input, argv, counter, &st);
			}
			if (status == 0)
			{
				free(input);
				return (0);
			}
		}
	}
	return (status);
}
/**
 * check_builtin - check builtin
 *
 * @cmd:command to check
 * Return: 0 Succes -1 Fail
 */
int check_builtin(char **cmd)
{
	bul_t fun[] = {
		{"cd", change_dir},
		{"echo", echo_bul},
		{"setenv", setenv_builtin},
		{"unsetenv", unsetenv_builtin},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;
		if (*cmd == NULL)
	{
		return (-1);
	}

	while ((fun + i)->command)
	{
		if (_strcmp(cmd[0], (fun + i)->command) == 0)
			return (1);
		i++;
	}
	return (-1);
}
/**
 * creat_envi - Creat Array of Enviroment Variable
 * @envi: Array of Enviroment Variable
 * Return: Void
 */
void creat_envi(char **envi)
{
	int i;

	for (i = 0; environ[i]; i++)
		envi[i] = _strdup(environ[i]);
	envi[i] = NULL;
}
