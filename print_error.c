#include "shell.h"
#include <stdlib.h>
/**
 * print_error - 
 */

void print_error(int on, char *var_name, char *type, char *name)
{
	char *str, *error_mess, *mess;
	char i;
	
	str = malloc(sizeof(char) * 10);

	_itoa(on, str, 10);
	error_mess = malloc(sizeof(char) * 200);

	if (!_strcmp(var_name, "exit"))
	{
		mess = "Illagal number: ";
	}
	else
	{
		mess = "";
	}
	snprintf(error_mess, 200, "%s%s %s: %s not found\n", name, str, mess, var_name);

	write(STDERR_FILENO, error_mess, _strlen(error_mess));
	free(str);
	free(error_mess);
}
