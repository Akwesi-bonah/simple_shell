#include "shell.h"
#include <stdlib.h>
/**
 * print_error - print error
 * @on: number of commands
 * @var_name: command
 * @type: error of the command
 * @name: name of execution
 */
void print_error(int on, char *var_name, char *type, char *name)
{
	char *str, *err, *msg;
	char i;

	str = malloc(sizeof(char) * 10);
	_itoa(on, str, 10);
	err = malloc(sizeof(char) * 200);

	if (!_strcmp(var_name, "exit"))
	{
		msg = "Illagal number: ";
	}
	else
	{
		msg = "";
	}
	snprintf(err, 200, "%s%s%s: %s not found\n", name, str, msg, var_name);
	write(STDERR_FILENO, err, _strlen(err));
	free(str);
	free(err);
}
